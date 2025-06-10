#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// 打印当前工作目录
void print_current_path() {
    std::cout << "当前目录: " << fs::current_path().string() << std::endl;
}

// 列出当前目录下所有文件和子目录
void cmd_ls() {
    std::cout << "目录列表：" << std::endl;
    for (auto& entry : fs::directory_iterator(fs::current_path())) {
        if (entry.is_directory()) {
            std::cout << "[目录]  " << entry.path().filename().string() << std::endl;
        }
        else if (entry.is_regular_file()) {
            std::cout << "[文件] " << entry.path().filename().string() << std::endl;
        }
        else {
            std::cout << "[其它] " << entry.path().filename().string() << std::endl;
        }
    }
}

// 切换目录：相对路径或绝对路径均可，如果路径无效则报错
void cmd_cd(const std::string& target) {
    fs::path new_path = target;
    try {
        fs::current_path(new_path);
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "错误：无法切换到目录 \"" << target << "\"。(" << e.what() << ")" << std::endl;
    }
}

// 创建新目录
void cmd_mkdir(const std::string& dirname) {
    fs::path dirpath = fs::current_path() / dirname;
    try {
        if (fs::create_directory(dirpath)) {
            std::cout << "成功：已创建目录 " << dirpath.string() << std::endl;
        }
        else {
            std::cerr << "失败：目录可能已存在或创建失败 " << dirpath.string() << std::endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "错误：创建目录时出错。(" << e.what() << ")" << std::endl;
    }
}

// 删除文件（仅删除常规文件）
void cmd_rm(const std::string& filename) {
    fs::path filepath = fs::current_path() / filename;
    try {
        if (!fs::exists(filepath)) {
            std::cerr << "错误：要删除的文件不存在 " << filepath.string() << std::endl;
            return;
        }
        if (fs::is_directory(filepath)) {
            std::cerr << "错误：目标是一个目录，请使用其它命令删除目录" << std::endl;
            return;
        }
        if (fs::remove(filepath)) {
            std::cout << "成功：已删除文件 " << filepath.string() << std::endl;
        }
        else {
            std::cerr << "失败：删除文件失败 " << filepath.string() << std::endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "错误：删除文件时出错。(" << e.what() << ")" << std::endl;
    }
}

// 打开并读取文件内容到控制台
void cmd_cat(const std::string& filename) {
    fs::path filepath = fs::current_path() / filename;
    if (!fs::exists(filepath) || !fs::is_regular_file(filepath)) {
        std::cerr << "错误：文件不存在或不是常规文件 " << filepath.string() << std::endl;
        return;
    }

    std::ifstream ifs(filepath, std::ios::in);
    if (!ifs.is_open()) {
        std::cerr << "错误：无法打开文件 " << filepath.string() << std::endl;
        return;
    }

    std::cout << "---- 文件内容开始 ----" << std::endl;
    std::string line;
    while (std::getline(ifs, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "---- 文件内容结束 ----" << std::endl;
    ifs.close();
}

// 向已有文件末尾追加写入内容
void cmd_append(const std::string& filename) {
    fs::path filepath = fs::current_path() / filename;
    std::ofstream ofs(filepath, std::ios::app);
    if (!ofs.is_open()) {
        std::cerr << "错误：无法打开或创建文件 " << filepath.string() << std::endl;
        return;
    }

    std::cout << "请输入要追加写入的内容，单独输入 \":wq\" （不含引号）保存并退出：" << std::endl;
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == ":wq") break;
        ofs << line << std::endl;
    }
    ofs.close();
    std::cout << "提示：追加写入已完成。" << std::endl;
}

// 新建并写入文件（覆盖已有同名文件）
void cmd_write(const std::string& filename) {
    fs::path filepath = fs::current_path() / filename;
    std::ofstream ofs(filepath, std::ios::out);
    if (!ofs.is_open()) {
        std::cerr << "错误：无法创建或打开文件 " << filepath.string() << std::endl;
        return;
    }

    std::cout << "请输入要写入的内容，单独输入 \":wq\" （不含引号）保存并退出：" << std::endl;
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == ":wq") break;
        ofs << line << std::endl;
    }
    ofs.close();
    std::cout << "提示：写入已完成。" << std::endl;
}

int main() {
    std::cout << "===== 简易文件系统演示程序 =====" << std::endl;
    std::cout << "支持命令：" << std::endl;
    std::cout << "  ls           （列出当前目录内容，list directory）" << std::endl;
    std::cout << "  cd <路径>    （切换目录，change directory）" << std::endl;
    std::cout << "  mkdir <名称> （创建新目录，make directory）" << std::endl;
    std::cout << "  rm <文件名>  （删除文件，remove file）" << std::endl;
    std::cout << "  cat <文件名> （查看文件内容，concatenate）" << std::endl;
    std::cout << "  append <文件名> （向文件追加内容，append to file）" << std::endl;
    std::cout << "  write <文件名>  （新建并写入文件，write file）" << std::endl;
    std::cout << "  exit         （退出程序，exit）" << std::endl;

    std::string input;
    while (true) {
        print_current_path();
        std::cout << ">> ";
        std::getline(std::cin, input);
        if (input.empty()) continue;

        // 拆分命令和参数
        std::string cmd;
        std::string arg;
        size_t pos = input.find(' ');
        if (pos == std::string::npos) {
            cmd = input;
        }
        else {
            cmd = input.substr(0, pos);
            arg = input.substr(pos + 1);
        }

        if (cmd == "ls") {
            cmd_ls();
        }
        else if (cmd == "cd") {
            if (arg.empty()) {
                std::cerr << "用法提示：cd <路径> （示例：cd subdir）" << std::endl;
            }
            else {
                cmd_cd(arg);
            }
        }
        else if (cmd == "mkdir") {
            if (arg.empty()) {
                std::cerr << "用法提示：mkdir <目录名> （示例：mkdir new_folder）" << std::endl;
            }
            else {
                cmd_mkdir(arg);
            }
        }
        else if (cmd == "rm") {
            if (arg.empty()) {
                std::cerr << "用法提示：rm <文件名> （示例：rm file.txt）" << std::endl;
            }
            else {
                cmd_rm(arg);
            }
        }
        else if (cmd == "cat") {
            if (arg.empty()) {
                std::cerr << "用法提示：cat <文件名> （示例：cat file.txt）" << std::endl;
            }
            else {
                cmd_cat(arg);
            }
        }
        else if (cmd == "append") {
            if (arg.empty()) {
                std::cerr << "用法提示：append <文件名> （示例：append file.txt）" << std::endl;
            }
            else {
                cmd_append(arg);
            }
        }
        else if (cmd == "write") {
            if (arg.empty()) {
                std::cerr << "用法提示：write <文件名> （示例：write file.txt）" << std::endl;
            }
            else {
                cmd_write(arg);
            }
        }
        else if (cmd == "exit") {
            std::cout << "退出程序。再见！" << std::endl;
            break;
        }
        else {
            std::cerr << "未知命令：" << cmd << "。请参照如下支持命令列表：" << std::endl;
            std::cerr << "  ls, cd <路径>, mkdir <目录名>, rm <文件名>, cat <文件名>, append <文件名>, write <文件名>, exit" << std::endl;
        }
    }

    return 0;
}
