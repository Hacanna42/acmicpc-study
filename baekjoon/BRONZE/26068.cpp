// 백준: 치킨댄스를 추는 곰곰이를 본 임스
// https://www.acmicpc.net/problem/26068
// 2024-01-31
// 업다운디펜스 디버깅용

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;

    std::vector<int> expiration(N);
    for (int i = 0; i < N; ++i) {
        std::string input;
        std::cin >> input;

        expiration[i] = std::stoi(input.substr(2));
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (expiration[i] <= 90) {
            count++;
        }
    }

    std::cout << count << "\n";

    return 0;
}
