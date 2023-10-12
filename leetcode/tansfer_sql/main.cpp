#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("data.txt");  // 打开文件

    if (!file.is_open()) {
        std::cerr << "无法打开文件!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {  // 逐行读取
        std::cout << line << std::endl;
    }

    file.close();  // 关闭文件
    return 0;
}
