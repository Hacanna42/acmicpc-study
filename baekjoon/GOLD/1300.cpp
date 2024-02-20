// 백준: K번째 수
// https://www.acmicpc.net/problem/1300
// 2024-01-16

#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long long N, k;
    std::cin >> N >> k;

    long long low = 1;
    long long high = N * N;
    long answer = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = 0;
        // 각 층에서 mid보다 작은 수의 개수는, 나머지의 몫과 동일하다.
        for (long long i = 1; i <= N; ++i) {
            long long temp = mid / i;
            if (temp > N)
                temp = N;
            count += temp;
        }

        if (count >= k) {
            high = mid - 1;
            answer = mid;
        } else
            low = mid + 1;
    }

    std::cout << answer;
    return 0;
}