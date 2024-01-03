// 백준: 가로수
// https://www.acmicpc.net/problem/2485
// 2024-01-03

#include <iostream>
#include <vector>

int gcd(long a, long b) {
    while (b != 0) {
        long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int N;
    int prev_num = 0;
    std::vector<int> distance;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        if (prev_num != 0) distance.push_back(temp - prev_num);
        prev_num = temp;
    }

    int result = distance[0];
    for (int i = 1; i < distance.size(); ++i) {
        result = gcd(result, distance[i]);
    }

    int count = 0;
    for (auto iter : distance) {
        count += iter;
    }

    std::cout << (count - (distance.size() * result)) / result;

    return 0;
}