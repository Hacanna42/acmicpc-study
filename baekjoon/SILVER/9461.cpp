// 백준: 파도반 수열
// https://www.acmicpc.net/problem/9461
// 2024-01-10

#include <iostream>
#include <vector>
std::vector<long long> p(101, -1);

long long dp(int n) {
    for (int i = 4; i <= n; ++i) {
        if (p[i] == -1) p[i] = p[i - 2] + p[i - 3];
    }
    return p[n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        std::cout << dp(temp) << "\n";
    }
    return 0;
}