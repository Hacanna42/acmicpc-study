// 백준: 그룹 단어 체커
// https://www.acmicpc.net/problem/1316
// 2023-12-20

#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();  // 이전 입력에서 남은 개행문자 제거
    std::vector<std::string> words(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, words[i]);
    }
    for (int i = 0; i < words.size(); i++) {
        std::vector<int> alphabet_shown(26, 0);
        bool is_group = true;
        for (int j = 0; j < words[i].length(); j++) {
            if (j != 0 && words[i][j] != words[i][j - 1]) {
                alphabet_shown[words[i][j] - 'a']++;
            } else if (j == 0)
                alphabet_shown[words[i][j] - 'a']++;
        }
        for (int temp : alphabet_shown) {
            if (temp > 1) is_group = false;
        }
        if (is_group) count++;
    }

    std::cout << count;

    return 0;
}