// 백준: 신나는 함수 실행
// https://www.acmicpc.net/problem/9184
// 2024-01-10

#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<int> > > w(
    101, std::vector<std::vector<int> >(101, std::vector<int>(101, -1)));

int dp(int a, int b, int c) {
    // 인덱스 조정
    int aa = a + 50;
    int bb = b + 50;
    int cc = c + 50;

    if (w[aa][bb][cc] != -1) return w[aa][bb][cc];
    if (a <= 0 || b <= 0 || c <= 0) {
        w[aa][bb][cc] = 1;
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        w[aa][bb][cc] = dp(20, 20, 20);
        return w[aa][bb][cc];
    }
    if (a < b && b < c) {
        w[aa][bb][cc] = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c);
        return w[aa][bb][cc];
    } else {
        w[aa][bb][cc] = dp(a - 1, b, c) + dp(a - 1, b - 1, c) +
                        dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1);
        return w[aa][bb][cc];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    while (1) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        std::cout << "w(" << a << ", " << b << ", " << c
                  << ") = " << dp(a, b, c) << std::endl;
    }
    return 0;
}