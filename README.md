# 🚀 C++ Multitasking  
**Muhammad Reza Heidary**  [![Gmail](https://img.shields.io/badge/Gmail-D14836?logo=gmail&logoColor=white)](mailto:muhammadreza.heidary@gmail.com)  [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/muhammad-reza-heidary/)  
*Embedded Systems Designer | C++ Developer | IoT & CCTV Surveillance Specialist*  


---

## ⚡ About This Repository  
A comprehensive collection of **C++ Multitasking** techniques, including:  

✅ **Task Management** – Creating, managing, and synchronizing tasks  
✅ **Synchronization** – Atomic condition variables  
✅ **Concurrency** – Managing shared resources efficiently  
✅ **Performance Optimization** – Leveraging multi-core systems  
✅ **Zombie Threads Prevention** – Avoiding orphaned processes  

---

## 🛠️ Topics Covered  

🔹 **Task Creation & Lifecycle**  
🔹 **Condition Variables & Synchronization Primitives**  
🔹 **Task Pool Implementation**  
🔹 **Atomic Operations & Memory Order**  
🔹 **Producer-Consumer & Parallel Algorithms**  
🔹 **Zombie Threads Handling & Prevention**  

---

## 🗒 What does this code do?

🔹 **It creates one mother task, which is forked into 5 other tasks**  
🔹 **Each task runs a while(true) loop with atomic-safe operations**  
🔹 **One task manually faces a core dump after 10 seconds!**  
🔹 **After the core dump, only the affected task stops, while the others continue their job**  
🔹 **The coredumped task does not affect the main task, ensuring system stability**  
🔹 **This implementation prevents zombie threads**  
🔹 **You can monitor tasks in the system monitor or use `htop` on Ubuntu**  

---

## 🖥️ How to Install and Use `htop` on Ubuntu  

### Installation:  
Run the following command in the terminal to install `htop`:  
```bash
sudo apt update && sudo apt install htop
```
To launch htop, simply type:
```bash
htop
```
This will display an interactive process viewer where you can monitor running tasks, CPU usage, and memory consumption in real time.

---

💡 **Let's connect and collaborate on cutting-edge C++ and IoT projects!** 🚀  
