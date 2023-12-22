// 백준: 약수 구하기
// https://www.acmicpc.net/problem/2501
// 2023-12-22

#include <iostream>
#include <vector>
int main() {
    int N, K;
    std::vector<int> divisor_list;
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) divisor_list.push_back(i);
    }
    std::cout << divisor_list[K - 1];
    return 0;
}