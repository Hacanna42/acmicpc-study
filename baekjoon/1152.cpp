// 백준: 단어의 개수
// https://www.acmicpc.net/problem/1152
// 2023-12-14

#include <iostream>
#include <sstream>
int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int a = 0;
    std::string word;
    while (ss >> word) {
        a++;
    }
    std::cout << a;

    // 아니,, 중복 단어 체크해야하는 줄 앎..
    // std::string line;
    // std::vector<std::string> words;
    // std::getline(std::cin, line);
    // std::stringstream ss(line);
    // std::string word;
    // while (ss >> word) {
    //     bool isDuplicated = false;
    //     for (std::string elem : words) {
    //         if (elem == word) {
    //             isDuplicated = true;
    //             break;
    //         }
    //     }
    //     if (!isDuplicated) words.push_back(word);
    // }
    // std::cout << words.size();
    // return 0;
}