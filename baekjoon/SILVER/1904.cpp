// 백준: 01타일
// https://www.acmicpc.net/problem/1904
// 2024-01-10

/*
DP는 큰 문제를 작은 문제로 쪼개서 풀어야 한다.
작은 문제를 정의하기 위한 점화식을 찾자.
dp[n]을 길이가 n인 수열을 만들 수 있는 경우의 수라고 정의하면
dp[1] = 1
dp[2] = 11, 00
dp[3] = 100, 001, 111
dp[4] = 1100, 0011, 1001, 1111, 0000
길이가 n인 수열을 만드는 방법을 두가지로 나눌 수 있다.
n-1의 끝에 1을 추가하거나, n-2의 끝에 00을 추가하거나.
따라서 점화식은 dp[n] = dp[n-1] + dp[n-2]가 된다.
*/

#include <iostream>
#include <vector>

std::vector<int> memo(1000001, -1);
int dp(int n) {
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i <= n; ++i) {
        if (memo[i] != -1) return memo[i];
        memo[i] = (memo[i - 1] + memo[i - 2]) % 15746;
    }
    return memo[n];
}

int main() {
    int N;
    std::cin >> N;
    std::cout << dp(N);
    return 0;
}