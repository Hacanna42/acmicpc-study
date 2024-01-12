// 백준: 인간-컴퓨터 상호작용
// https://www.acmicpc.net/problem/16139
// 2024-01-12

#include <iostream>
#include <string>
#include <vector>

int main() {
    // 문자열 입력
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string str;
    std::getline(std::cin, str);
    std::vector<std::vector<int> > prefix_alphabets(
        26, std::vector<int>(str.length(), 0));
    std::vector<int> prefix_each(26, 0);
    for (int i = 0; i < str.length(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i != 0) prefix_alphabets[j][i] = prefix_alphabets[j][i - 1];
        }
        prefix_alphabets[(str[i] - 'a')][i] = ++prefix_each[(str[i] - 'a')];
    }

    // 질문 개수 입력
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        char goal_alphabet;
        int range1, range2;
        std::cin >> goal_alphabet >> range1 >> range2;
        int result = prefix_alphabets[(goal_alphabet - 'a')][range2];
        if (range1 > 0)
            result -= prefix_alphabets[(goal_alphabet - 'a')][range1 - 1];
        std::cout << result << "\n";
    }
    return 0;
}