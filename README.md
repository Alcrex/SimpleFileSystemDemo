简易文件系统演示程序 / Simple File System Demo
English | 中文

中文
项目简介
这是一个用C++编写的简易文件系统演示程序，模拟了基本的文件和目录操作命令。程序提供了一个交互式命令行界面，用户可以通过类似Unix/Linux的命令来操作文件系统。

功能特性
目录浏览: 列出当前目录下的所有文件和子目录
目录切换: 支持相对路径和绝对路径的目录切换
目录创建: 创建新的目录
文件删除: 删除指定的文件
文件查看: 显示文件的完整内容
文件写入: 创建新文件并写入内容
文件追加: 向现有文件末尾追加内容
支持的命令
命令	语法	描述
ls	ls	列出当前目录内容
cd	cd <路径>	切换到指定目录
mkdir	mkdir <目录名>	创建新目录
rm	rm <文件名>	删除指定文件
cat	cat <文件名>	查看文件内容
write	write <文件名>	创建并写入文件
append	append <文件名>	向文件追加内容
exit	exit	退出程序
编译和运行
系统要求
C++17 或更高版本
支持 std::filesystem 的编译器（如 GCC 8+, Clang 7+, MSVC 2017+）
编译命令
使用 g++:

g++ -std=c++17 -o file_system_demo main.cpp
使用 clang++:

clang++ -std=c++17 -o file_system_demo main.cpp
在某些系统上可能需要链接文件系统库:

g++ -std=c++17 -lstdc++fs -o file_system_demo main.cpp
运行程序
./file_system_demo
使用示例
===== 简易文件系统演示程序 =====
当前目录: /home/user/demo
>> ls
[文件] main.cpp
[目录] test_folder
>> mkdir new_folder
成功：已创建目录 /home/user/demo/new_folder
>> cd new_folder
当前目录: /home/user/demo/new_folder
>> write hello.txt
请输入要写入的内容，单独输入 ":wq" （不含引号）保存并退出：
Hello, World!
This is a test file.
:wq
提示：写入已完成。
>> cat hello.txt
---- 文件内容开始 ----
Hello, World!
This is a test file.
---- 文件内容结束 ----
>> exit
退出程序。再见！
注意事项
程序在当前工作目录下运行，请确保有适当的读写权限
rm 命令只能删除文件，不能删除目录
文件写入和追加操作使用 :wq 作为结束标记
路径操作支持相对路径和绝对路径
English
Project Overview
This is a simple file system demonstration program written in C++, simulating basic file and directory operations. The program provides an interactive command-line interface where users can operate the file system using Unix/Linux-like commands.

Features
Directory Browsing: List all files and subdirectories in the current directory
Directory Navigation: Support both relative and absolute path navigation
Directory Creation: Create new directories
File Deletion: Delete specified files
File Viewing: Display complete file contents
File Writing: Create new files and write content
File Appending: Append content to existing files
Supported Commands
Command	Syntax	Description
ls	ls	List directory contents
cd	cd <path>	Change to specified directory
mkdir	mkdir <dirname>	Create new directory
rm	rm <filename>	Remove specified file
cat	cat <filename>	Display file contents
write	write <filename>	Create and write to file
append	append <filename>	Append content to file
exit	exit	Exit the program
Compilation and Execution
System Requirements
C++17 or higher
Compiler with std::filesystem support (e.g., GCC 8+, Clang 7+, MSVC 2017+)
Compilation Commands
Using g++:

g++ -std=c++17 -o file_system_demo main.cpp
Using clang++:

clang++ -std=c++17 -o file_system_demo main.cpp
On some systems, you may need to link the filesystem library:

g++ -std=c++17 -lstdc++fs -o file_system_demo main.cpp
Running the Program
./file_system_demo
Usage Example
===== Simple File System Demo =====
Current Directory: /home/user/demo
>> ls
[File] main.cpp
[Directory] test_folder
>> mkdir new_folder
Success: Created directory /home/user/demo/new_folder
>> cd new_folder
Current Directory: /home/user/demo/new_folder
>> write hello.txt
Enter content to write, type ":wq" alone to save and exit:
Hello, World!
This is a test file.
:wq
Note: Writing completed.
>> cat hello.txt
---- File Content Start ----
Hello, World!
This is a test file.
---- File Content End ----
>> exit
Exiting program. Goodbye!
Important Notes
The program runs in the current working directory, ensure appropriate read/write permissions
The rm command can only delete files, not directories
File writing and appending operations use :wq as the termination marker
Path operations support both relative and absolute paths
Project Structure
file_system_demo/
├── main.cpp          # Main source file
├── README.md         # This documentation
└── file_system_demo  # Compiled executable (after compilation)
Contributing
Feel free to submit issues and enhancement requests. Contributions are welcome!

License
This project is open source and available under the MIT License.

