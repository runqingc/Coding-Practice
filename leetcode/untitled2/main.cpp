#include <iostream>
#include <string>
#include <random>
#include <vector>

std::string generateRandomString(int length) {
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, sizeof(alphanum) - 2); // -2 因为不包括末尾的 '\0'

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += alphanum[dist(gen)];
    }

    return result;
}

int main() {
    int numStrings = 5;  // 假设生成5个字符串
    std::vector<std::string> strings;

    for (int i = 0; i < numStrings; ++i) {
        strings.push_back(generateRandomString(10));
    }

    for (const auto& str : strings) {
        std::cout << str << std::endl;
    }

    return 0;
}
