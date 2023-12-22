// 백준: 소수 찾기
// https://www.acmicpc.net/problem/1978
// 2023-12-22

#include <iostream>
int main() {
    int N;
    int count = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        bool isdec = true;
        std::cin >> a;
        for (int j = 2; j < a; j++) {
            if (a % j == 0) {
                isdec = false;
                break;
            }
        }
        if (isdec && a != 1) count++;
    }
    std::cout << count;
    return 0;
}