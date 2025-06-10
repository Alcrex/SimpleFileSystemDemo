# 🗂️ Simple File System Demo / 简易文件系统演示程序

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue)](https://en.cppreference.com/w/cpp/17)

A simple terminal-based file system tool built in C++17 using `<filesystem>`.  
基于 C++17 `<filesystem>` 实现的终端文件系统交互工具，支持基本的文件与目录操作。

---

## 📚 Table of Contents / 目录

- [Features / 功能](#-features--功能)
- [Build & Run / 编译与运行](#-build--run--编译与运行)
- [Usage Examples / 使用示例](#-usage-examples--使用示例)
- [Notes / 注意事项](#-notes--注意事项)
- [License / 许可证](#-license--许可证)

---

## ✅ Features / 功能

- `ls`：列出当前目录内容 / List current directory
- `cd <路径>`：切换工作目录 / Change directory
- `mkdir <目录名>`：创建新目录 / Make a new directory
- `rm <文件名>`：删除文件（不支持目录）/ Delete file (not directory)
- `cat <文件名>`：显示文件内容 / Display file contents
- `append <文件名>`：追加写入文件 / Append to file
- `write <文件名>`：新建或覆盖写入文件 / Write or overwrite file
- `exit`：退出程序 / Exit the program

---

## 🧱 Build & Run / 编译与运行

### Prerequisites / 先决条件

- C++17-compatible compiler（如 g++ ≥ 7 / MSVC ≥ 2017）

### Build / 编译

```bash
g++ -std=c++17 -o simple_fs main.cpp
