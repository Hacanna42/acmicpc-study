// 백준: 약수
// https://www.acmicpc.net/problem/1037
// 2024-01-05

/*
이 문제의 의도는 주어진 진짜 약수들로부터 원래의 수 N을 구하는 것이고.
N은 주어진 진짜 약수들 중 가장 작은 값 * 가장 큰 값으로 구할 수 있다.
주어진 진짜 약수들이 N의 모든 소인수를 포함하고 있기 때문이다.
*/
#include <iostream>

int main() {
    int N;
    int max = 0;
    int min = 1000000;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }
    std::cout << min * max;
    return 0;
}