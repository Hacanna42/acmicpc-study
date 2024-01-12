// 백준: LCS
// https://www.acmicpc.net/problem/9251
// 2024-01-12

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> sequences;
std::vector<std::vector<int> > memo;

int LCS_DP() {
    for (int i = 1; i <= sequences[0].length(); ++i) {
        for (int j = 1; j <= sequences[1].length(); ++j) {
            if (sequences[0][i - 1] == sequences[1][j - 1])
                memo[i][j] = memo[i - 1][j - 1] + 1;
            else
                memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
        }
    }

    return memo[sequences[0].length()][sequences[1].length()];
}
int main() {
    std::string A, B;
    std::cin >> A >> B;
    sequences.push_back(A);
    sequences.push_back(B);
    memo.assign(sequences[0].length() + 1,
                std::vector<int>(sequences[1].length() + 1));
    std::cout << LCS_DP();
    return 0;
}