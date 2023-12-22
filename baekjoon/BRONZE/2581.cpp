// 백준: 소수
// https://www.acmicpc.net/problem/2581
// 2023-12-22

#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int M, N;
    std::vector<int> primelist;
    std::cin >> M >> N;
    for (int i = M; i <= N; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime && i != 1) primelist.push_back(i);
    }
    int count = 0;
    for (int i = 0; i < primelist.size(); i++) {
        count += primelist[i];
    }
    if (primelist.size() != 0)
        std::cout << count << std::endl << primelist[0];
    else
        std::cout << "-1";
    return 0;
}