// 백준: 개수 세기
// https://www.acmicpc.net/problem/10807
// 2023-11-08

#include <iostream>

int main() {
    int N;
    int searchThis;
    int answer = 0;
    std::cin >> N;
    int *list = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> list[i];
    }
    std::cin >> searchThis;
    for (int i = 0; i < N; i++) {
        if (list[i] == searchThis) answer++;
    }
    std::cout << answer;
    return 0;
}