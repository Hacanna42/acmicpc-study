// 백준: 행성 정렬
// https://www.acmicpc.net/problem/25344
// 2024-02-01
// 업랜디

#include <algorithm>
#include <iostream>
#include <vector>

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long long N;
    std::vector<long long> nums;
    std::cin >> N;
    for (long i = 0; i < N - 2; ++i) {
        long long temp;
        std::cin >> temp;
        nums.push_back(temp);
    }

    int answer = nums[0];
    for (int i = 1; i < N - 2; ++i) {
        answer = lcm(answer, nums[i]);
    }

    std::cout << answer;

    return 0;
}