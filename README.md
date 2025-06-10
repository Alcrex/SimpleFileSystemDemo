# 简易文件系统演示程序 README  
# Simple Filesystem Demo Program README

## 概述 / Overview
这是一个用 C++ 编写的简易文件系统操作演示程序，利用 `std::filesystem` 提供基本的文件和目录管理功能。程序以命令行界面的形式运行，支持查看目录、切换路径、创建目录、删除文件、读写文件等操作，旨在模拟类似 Unix 的基本文件系统命令，方便学习和测试。  
This is a simple filesystem operation demo program written in C++, utilizing `std::filesystem` to provide basic file and directory management functions. The program runs in a command-line interface, supporting operations like listing directories, changing paths, creating directories, deleting files, and reading/writing files, aiming to simulate basic Unix-like filesystem commands for learning and testing.

## 依赖 / Dependencies
- **语言 / Language**: C++17 或更高版本 / C++17 or higher
- **头文件 / Headers**:
  - `<iostream>`: 用于标准输入输出操作 / For standard input and output operations
  - `<string>`: 处理字符串输入和参数 / For handling string input and parameters
  - `<filesystem>`: 提供文件系统操作功能（如目录切换、文件删除等） / Provides filesystem operations (e.g., directory switching, file deletion)
  - `<fstream>`: 支持文件读写操作 / Supports file read and write operations
- **编译器 / Compiler**: 支持 C++17 的编译器，例如 / Compilers supporting C++17, e.g.:
  - GCC 7.0 或以上 / GCC 7.0 or above
  - Clang 5.0 或以上 / Clang 5.0 or above
  - MSVC 19.14 或以上（Visual Studio 2017 及更新版本） / MSVC 19.14 or above (Visual Studio 2017 and later)
- **平台 / Platform**: 跨平台支持（Windows、Linux、macOS），依赖 `std::filesystem` 的实现 / Cross-platform support (Windows, Linux, macOS), depends on `std::filesystem` implementation

## 功能 / Features
程序通过命令行交互，提供以下功能命令：  
The program provides the following commands via a command-line interface:
- **ls**: 列出当前目录下的文件和子目录，标注类型（[目录]、[文件] 或 [其它]）。  
  Lists files and subdirectories in the current directory, labeled by type ([目录] for directory, [文件] for file, or [其它] for others).
- **cd <路径> / cd <path>**: 切换当前工作目录，支持相对路径和绝对路径，路径无效时会报错。  
  Changes the current working directory, supports relative and absolute paths, and reports an error if the path is invalid.
- **mkdir <名称> / mkdir <name>**: 在当前目录下创建新目录，成功或失败均有提示。  
  Creates a new directory in the current directory, with success or failure prompts.
- **rm <文件名> / rm <filename>**: 删除指定常规文件，不支持删除目录，文件不存在或操作失败时会报错。  
  Deletes the specified regular file, does not support directory deletion, and reports an error if the file doesn’t exist or the operation fails.
- **cat <文件名> / cat <filename>**: 读取并显示指定文件内容，文件不存在或非常规文件时会报错。  
  Reads and displays the content of the specified file, reports an error if the file doesn’t exist or isn’t a regular file.
- **append <文件名> / append <filename>**: 向指定文件末尾追加内容，输入 `:wq` 保存并退出。  
  Appends content to the end of the specified file, enter `:wq` to save and exit.
- **write <文件名> / write <filename>**: 新建或覆盖文件并写入内容，输入 `:wq` 保存并退出。  
  Creates or overwrites a file and writes content, enter `:wq` to save and exit.
- **exit**: 退出程序。  
  Exits the program.

## 编译与运行 / Compilation and Execution
### 编译 / Compilation
确保使用支持 C++17 的编译器。示例编译命令：  
Ensure a C++17-compatible compiler is used. Example compilation command:
```bash
g++ -std=c++17 main.cpp -o filesystem_demo
```
### 运行 / Execution
执行编译后的程序：  
Run the compiled program:
```bash
./filesystem_demo
```
程序启动后会显示支持的命令列表，输入命令并按回车执行。每次操作前会显示当前工作目录。  
After starting, the program displays the supported commands list. Enter a command and press Enter to execute. The current working directory is shown before each operation.

## 用法示例 / Usage Examples
1. **查看当前目录内容 / List current directory contents**:
   ```
   >> ls
   目录列表：
   [目录]  subdir
   [文件]  test.txt
   Directory list:
   [directory]  subdir
   [file]  test.txt
   ```
2. **切换目录 / Change directory**:
   ```
   >> cd subdir
   当前目录: /path/to/subdir
   Current directory: /path/to/subdir
   ```
3. **创建新目录 / Create a new directory**:
   ```
   >> mkdir new_folder
   成功：已创建目录 /path/to/new_folder
   Success: Directory created /path/to/new_folder
   ```
4. **写入文件 / Write to a file**:
   ```
   >> write note.txt
   请输入要写入的内容，单独输入 ":wq" （不含引号）保存并退出：
   Hello, world!
   :wq
   提示：写入已完成。
   Enter content to write, type ":wq" (without quotes) to save and exit:
   Hello, world!
   :wq
   Prompt: Write completed.
   ```
5. **查看文件内容 / View file content**:
   ```
   >> cat note.txt
   ---- 文件内容开始 ----
   Hello, world!
   ---- 文件内容结束 ----
   ---- File content start ----
   Hello, world!
   ---- File content end ----
   ```
6. **退出 / Exit**:
   ```
   >> exit
   退出程序。再见！
   Exiting program. Goodbye!
   ```

## 注意事项 / Notes
- **路径处理 / Path Handling**: 路径可以是相对路径或绝对路径，程序会尝试解析并切换。  
  Paths can be relative or absolute; the program attempts to parse and switch.
- **错误处理 / Error Handling**: 所有操作均包含错误检查，如文件不存在、权限不足等，错误信息会输出到控制台。  
  All operations include error checking, e.g., file not found, insufficient permissions, with errors output to the console.
- **限制 / Limitations**: `rm` 命令仅支持删除常规文件，不支持目录删除。  
  The `rm` command only supports deleting regular files, not directories.
- **输入格式 / Input Format**: 命令和参数以空格分隔，部分命令（如 `ls` 和 `exit`）无需参数。  
  Commands and arguments are space-separated; some commands (e.g., `ls` and `exit`) require no arguments.

## 代码结构 / Code Structure
- **命名空间 / Namespace**: 使用 `std::filesystem`（别名 `fs`）处理文件系统操作。  
  Uses `std::filesystem` (aliased as `fs`) for filesystem operations.
- **函数 / Functions**:
  - `print_current_path()`: 打印当前工作目录 / Prints the current working directory.
  - `cmd_ls()`: 列出目录内容 / Lists directory contents.
  - `cmd_cd(const std::string&)`: 切换目录 / Changes directory.
  - `cmd_mkdir(const std::string&)`: 创建目录 / Creates a directory.
  - `cmd_rm(const std::string&)`: 删除文件 / Deletes a file.
  - `cmd_cat(const std::string&)`: 读取文件内容 / Reads file content.
  - `cmd_append(const std::string&)`: 追加写入文件 / Appends to a file.
  - `cmd_write(const std::string&)`: 新建并写入文件 / Creates and writes to a file.
- **主循环 / Main Loop**: 在 `main()` 中通过命令行输入循环处理用户指令。  
  In `main()`, processes user commands in a loop via command-line input.

## 许可证 / License
本程序仅供学习和演示使用，未指定具体许可证。建议在实际应用中根据需求添加适当的许可证。  
This program is for learning and demonstration purposes only, with no specific license specified. It is recommended to add an appropriate license for practical use.
