// 백준: 단어 공부
// https://www.acmicpc.net/problem/1157
// 2023-12-20

// std::string으로 입력을 받고, a~z만큼의 배열 string.size()만큼
// 반복문을 돌리면서 해당하는 곳의 heap배열을 +1 마지막에 배열을 순회하면서 값이
// 가장 높은 원소를 찾고 출력하기, 단. 값이 가장 높은 원소가 두개 이상이면 ?
// 출력.

#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string line;
    std::cin >> line;
    int alphabet_frequency[26] = {0};
    for (int i = 0; i < line.size(); i++) {
        alphabet_frequency[std::tolower(line[i]) - 97]++;
    }

    int max = 0;
    int indicator = -1;
    bool is_max_duplicated = false;
    for (int i = 0; i < 26; i++) {
        if (alphabet_frequency[i] > max) {
            max = alphabet_frequency[i];
            indicator = i;
            is_max_duplicated = false;
        } else if (alphabet_frequency[i] == max) {
            is_max_duplicated = true;
        }
    }

    if (is_max_duplicated)
        std::cout << "?";
    else
        std::cout << static_cast<char>(
            std::toupper(static_cast<char>(indicator + 97)));
    return 0;
}