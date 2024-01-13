// 백준: 나머지 합
// https://www.acmicpc.net/problem/10986
// 2024-01-13

/*
어떤 수 M으로 나누어 떨어진다는 것은 M의 배수라는 뜻이고
모듈러 M한 값이 같은 두 쌍을 더하면 M의 배수가 된다.
따라서 이 문제는 모듈러 M의 누적합과 그 개수를 기록하고.
가능한 조합 쌍을 계산하면 된다 c*(c-1)/2
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, modular;
    std::cin >> N >> modular;
    std::vector<long> count(modular, 0);

    long long prefixSum = 0;
    long long answer = 0;
    for (int i = 0; i < N; ++i) {
        int number;
        std::cin >> number;
        prefixSum = (prefixSum + number) % modular;
        count[prefixSum]++;

        if (prefixSum == 0) answer++;
    }
    for (int i = 0; i < modular; ++i) {
        if (count[i] > 1) answer += count[i] * (count[i] - 1) / 2;
    }
    std::cout << answer;
    return 0;
}