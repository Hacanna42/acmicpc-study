// 백준: 골드바흐 파티션
// https://www.acmicpc.net/problem/17103
// 2024-01-03

#include <algorithm>
#include <iostream>
#include <vector>

// 에라토스테네스의 체를 쓸 수도 있었다. (쓰는게 좋았다)
bool isPrime(long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void getPrimeUntil(std::vector<long>& v, long limit) {
    for (long i = 2; i <= limit; ++i) {
        if (isPrime(i)) v.push_back(i);
    }
}

int main() {
    long N;
    std::vector<long> primes;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    getPrimeUntil(primes, 1000000);

    for (long i = 0; i < N; ++i) {
        long temp;
        std::cin >> temp;

        long maxIndex = 0;
        // temp보다 작은 숫자의 인덱스 추적
        for (auto iter : primes) {
            if (iter > temp) break;
            ++maxIndex;
        }
        // 숫자 조합
        long count = 0;
        for (long j = 0; j < maxIndex; ++j) {
            int diff = temp - primes[j];
            if (diff >= primes[j] &&
                std::binary_search(primes.begin(), primes.end(), diff))
                ++count;
        }
        std::cout << count << "\n";
    }
    return 0;
}