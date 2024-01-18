// 백준: 파일 합치기
// https://www.acmicpc.net/problem/11066
// 2024-01-18

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long dp(vector<long>& chapter_values, int size);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        int N;
        cin >> N;
        vector<long> chapter_values;
        for (int i = 0; i < N; ++i) {
            int temp;
            cin >> temp;
            chapter_values.push_back(temp);
        }
        cout << dp(chapter_values, chapter_values.size()) << "\n";
    }
    return 0;
}

long dp(vector<long>& chapter_values, int size) {
    vector<std::vector<long> > memo(size, std::vector<long>(size, INT_MAX));
    vector<long long> prefix(size + 1, 0);

    // 누적합 계산
    for (int i = 0; i < size; ++i) {
        prefix[i + 1] = prefix[i] + chapter_values[i];
    }

    // 길이가 1인 부분 집합의 최소 비용은 0
    for (int i = 0; i < size; ++i) {
        memo[i][i] = 0;
    }

    for (int len = 2; len <= size; ++len) {
        for (int start = 0; start <= size - len; ++start) {
            int end = start + len - 1;
            for (int k = start; k < end; ++k) {
                long cost = memo[start][k] + memo[k + 1][end] +
                            prefix[end + 1] - prefix[start];
                memo[start][end] = min(memo[start][end], cost);
            }
        }
    }

    return memo[0][size - 1];
}