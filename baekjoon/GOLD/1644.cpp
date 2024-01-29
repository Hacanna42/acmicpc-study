// 백준: 소수의 연속합
// https://www.acmicpc.net/problem/1644
// 2024-01-29

/* 예전에 배웠던 에라토스테네스의 체를 이용해서 소수를 구하자.
하나 이상의 연속합이기에, 소수 그 자체도 1로 된다는 것을 간과했다. :( */

#define LIMIT 4000500

#include <iostream>
#include <vector>

bool prime[LIMIT];
std::vector<int> primes;

void eratosthenes() {
    for (int p = 2; p * p <= LIMIT; ++p) {
        if (!prime[p]) {
            for (int i = p * p; i <= LIMIT; i += p) {
                prime[i] = true;
            }
        }
    }

    for (int i = 2; i <= LIMIT; ++i) {
        if (!prime[i]) primes.push_back(i);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    eratosthenes();
    // for (int i = 0; i < primes.size(); ++i) {
    //     std::cout << primes[i] << " ";
    // }
    int N;
    std::cin >> N;

    int start = 0, end = 0;
    int current_sum = 0;
    int count = 0;

    // 어차피 primes 배열이 널널하게 잡혀있어서, 굳이 끝 인덱스의 다음 부분까지
    // 순회를 안 돌려도 될듯.

    while (end < primes.size()) {
        // 연속된 소수 조합 발견
        if (current_sum == N) {
            count++;
            current_sum -= primes[start++];
        }
        // 소수의 합이 목표보다 작다면
        else if (current_sum < N) {
            // if (end == primes.size()) break;
            current_sum += primes[end++];
        }
        // 소수의 합이 목표보다 크다면
        else if (current_sum > N) {
            current_sum -= primes[start++];
        }
    }

    std::cout << count;
    return 0;
}