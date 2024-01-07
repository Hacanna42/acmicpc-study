// 백준: 칸토어 집합
// https://www.acmicpc.net/problem/4779
// 2024-01-07

#include <cmath>
#include <iostream>
#include <vector>

void cantorian_set(std::vector<int>& v, int p, int r) {
    if (p < r) {
        int div = ((r - p) + 1) / 3;
        for (int i = p + div; i < p + div * 2; ++i) {
            v[i] = 0;
        }
        cantorian_set(v, p, p + div - 1);
        cantorian_set(v, p + div * 2, r);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    while (true) {
        int N;
        std::cin >> N;
        std::vector<int> v(std::pow(3, N), 1);
        if (std::cin.eof()) break;
        cantorian_set(v, 0, v.size() - 1);
        for (const auto iter : v) {
            if (iter == 0)
                std::cout << " ";
            else
                std::cout << "-";
        }
        std::cout << "\n";
    }
    return 0;
}