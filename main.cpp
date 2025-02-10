#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <csignal>
#include <vector>
#include <atomic>
#include <chrono>
#include <thread>
#include <sys/prctl.h>

void setTaskName(const char* name) {
    prctl(PR_SET_NAME, name, 0, 0, 0);
}

std::atomic<bool> running1(true);
void taskFunction1() {
    setTaskName("Task_1");
    while (running1.load()) {
        std::cout << "Task 1 is running.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

std::atomic<bool> running2(true);
void taskFunction2() {
    setTaskName("Task_2");
    while (running2.load()) {
        std::cout << "Task 2 is running.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}

std::atomic<bool> running3(true);
void taskFunction3() {
    setTaskName("Task_3");
    auto start_time = std::chrono::steady_clock::now();
    while (running3.load()) {
        std::cout << "Task 3 is running.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        if (std::chrono::steady_clock::now() - start_time > std::chrono::seconds(10)) {
            int* ptr = nullptr;
            *ptr = 42; // Intentional segmentation fault (coredump)
        }
    }
}

std::atomic<bool> running4(true);
void taskFunction4() {
    setTaskName("Task_4");
    while (running4.load()) {
        std::cout << "Task 4 is running.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
}

std::atomic<bool> running5(true);
void taskFunction5() {
    setTaskName("Task_5");
    while (running5.load()) {
        std::cout << "Task 5 (callback) is executing.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
    }
}

void handleChildExit(int sig) {
    while (waitpid(-1, nullptr, WNOHANG) > 0);
}

int main() {
    signal(SIGCHLD, handleChildExit);
    std::cout << "Mother Task is starting..." << std::endl;
    std::vector<pid_t> pids;

    auto launchTask = [&](void (*taskFunc)()) {
        pid_t pid = fork();
        if (pid == 0) {
            taskFunc();
            exit(0);
        } else if (pid > 0) {
            pids.push_back(pid);
        } else {
            std::cerr << "Failed to fork process." << std::endl;
        }
    };

    launchTask(taskFunction1);
    launchTask(taskFunction2);
    launchTask(taskFunction3);
    launchTask(taskFunction4);
    launchTask(taskFunction5);

    for (auto pid : pids) {
        waitpid(pid, nullptr, 0);
    }

    return 0;
}
