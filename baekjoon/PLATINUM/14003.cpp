// 백준: 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003
// 2024-01-31

/* LIS 구현은 DP O(N^2)의 방식과 Binary Search O(NlogN)의 방법이 있다.
이진탐색 방법은 lower_bound 이용해서 값을 대체하며 진행한다. */

#include <algorithm>
#include <iostream>
#include <vector>

long long lower_bound(std::vector<long long>& lis, int num) {
    long long start = 0;
    long long end = lis.size();
    while (start < end) {
        long long mid = start + (end - start) / 2;
        if (lis[mid] < num) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

std::vector<int> arr;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        arr.push_back(temp);
    }

    // 요건 DP로 푼거
    // std::vector<int> dp(N, 1);
    // for (int i = 1; i < N; ++i) {
    //     for (int j = 0; j < i; ++j) {
    //         if (arr[j] < arr[i]) {
    //             dp[i] = std::max(dp[i], dp[j] + 1);
    //         }
    //     }
    // }

    // 요건 이진탐색
    std::vector<long long> lis;
    std::vector<long long>
        backtrace;  // 역추적하기 위해서, 각 lis의 인덱스 값을 쌓아주기
    std::vector<long long> answer;
    for (int i = 0; i < N; ++i) {
        long long num = arr[i];
        long long index = lower_bound(lis, num);
        if (index == lis.size()) {
            lis.push_back(num);
            backtrace.push_back(lis.size() - 1);
        } else {
            lis[index] = num;
            backtrace.push_back(index);
        }
    }

    /* 이 부분 너무 어렵다,, LIS를 역추적하기 위해선 각 인덱스를 저장할
     * 배열, 그리고 그 이전 인덱스를 저장할 배열 두개가 필요하다*/

    int temp = lis.size() - 1;
    for (int i = backtrace.size() - 1; i >= 0; --i) {
        if (backtrace[i] == temp) {
            answer.push_back(arr[i]);
            --temp;
        }
    }

    // std::sort(answer.begin(), answer.end());
    std::reverse(answer.begin(), answer.end());

    std::cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << " ";
    }

    return 0;
}