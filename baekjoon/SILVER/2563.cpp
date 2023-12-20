// 백준: 색종이
// https://www.acmicpc.net/problem/2563
// 2023-12-20

// 100, 100의 int 행렬을 생성하고 0으로 초기화한다.
// m부터 m+10까지의 행에 대해서 n부터 n+10의 열까지 1로 초기화.
// 마지막에 모든 행렬에 대한 값을 sum

#include <iostream>

int main() {
    int matrix[100][100] = {0};
    int count;
    std::cin >> count;
    int n, m;
    while (count--) {
        std::cin >> n >> m;
        for (int i = m; i < m + 10; i++) {
            for (int j = n; j < n + 10; j++) {
                matrix[i][j] = 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            answer += matrix[i][j];
        }
    }

    std::cout << answer;
    return 0;
}