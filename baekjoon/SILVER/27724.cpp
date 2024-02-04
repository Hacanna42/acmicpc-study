// 백준: 팝핀 소다
// https://www.acmicpc.net/problem/27724
// 2024-02-04

/* cmath의 로그 함수는 밑이 10인 로그까지 지원한다고 한다..
이외는 로그의 밑 변환 공식을 사용해야 한다고 함. */

#include <cmath>
#include <iostream>
int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    int total_game = std::log2(N);
    int win = std::log2(K);
    std::cout << ((win + M <= total_game) ? win + M : total_game);

    return 0;
}