# 简易文件系统演示程序 / Simple File System Demo

这是一个使用 C++17 编写的简易命令行文件系统模拟器，支持常见的文件和目录操作，例如 `ls`、`cd`、`mkdir`、`rm`、`cat` 等命令。

This is a simple command-line file system simulator written in C++17. It supports basic file and directory operations such as `ls`, `cd`, `mkdir`, `rm`, `cat`, and more.

## 目录 / Contents
- [🔧 编译要求 / Build Requirements](#编译要求--build-requirements)
- [🛠 编译示例 / Build Example](#编译示例--build-example)
- [编译（Windows 如遇链接错误）](#编译windows-如遇链接错误)
- [▶️ 使用方法 / Usage](#使用方法--usage)
- [📝 输入示例 / Input Examples](#输入示例--input-examples)
- [📁 功能说明 / Feature Summary](#功能说明--feature-summary)
- [📄 许可证 / License](#许可证--license)



## 🔧 编译要求 / Build Requirements

- C++17 支持的编译器（如 g++ 8+、MSVC 2017+）
- 标准库支持 `<filesystem>`

A C++17-compatible compiler with `<filesystem>` support is required.

## 🛠 编译示例 / Build Example

### Linux / macOS

```bash
g++ -std=c++17 -o fs_demo main.cpp
```

## 编译（Windows 如遇链接错误）

```bash
g++ -std=c++17 -o fs_demo main.cpp -lstdc++fs
```

## ▶️ 使用方法 / Usage
运行程序后，你将看到支持的命令提示。你可以像在命令行中一样操作文件系统。

After running the program, you'll be prompted with available commands. You can interact with the file system as if in a shell.

| 命令 (Command)   | 描述 (Description)                            |
| -------------- | ------------------------------------------- |
| `ls`           | 列出当前目录下所有文件和目录 / List all files and folders |
| `cd <路径>`      | 切换到指定目录 / Change current directory          |
| `mkdir <目录名>`  | 创建一个新目录 / Create a new directory            |
| `rm <文件名>`     | 删除一个普通文件 / Delete a regular file            |
| `cat <文件名>`    | 显示文件内容 / Display contents of a file         |
| `append <文件名>` | 向文件末尾追加内容 / Append text to a file           |
| `write <文件名>`  | 覆盖写入文件 / Overwrite and write to a file      |
| `exit`         | 退出程序 / Exit the program                     |


## 📝 输入示例 / Input Examples

```bash
>> mkdir test_dir
>> cd test_dir
>> write hello.txt
请输入要写入的内容，单独输入 ":wq" 保存并退出:
Hello, world!
:wq

>> cat hello.txt
Hello, world!

>> append hello.txt
请输入要追加写入的内容，单独输入 ":wq" 保存并退出:
This is appended.
:wq

>> cat hello.txt
Hello, world!
This is appended.
```

## 📁 功能说明 / Feature Summary
✅ 跨平台支持（Windows / Linux / macOS）
✅ 简易命令解释器
✅ 错误处理友好
✅ 直接使用标准库，无第三方依赖

Cross-platform file system utility demo with friendly error handling and interactive command interface. No external dependencies.

## 📄 许可证 / License
此项目为教学用途，无特定许可证。你可以自由使用、修改、学习。
This project is intended for educational purposes. You are free to use, modify, and learn from it.
