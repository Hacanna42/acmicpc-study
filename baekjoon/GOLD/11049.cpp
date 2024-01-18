// 백준: 행렬 곱셈 순서
// https://www.acmicpc.net/problem/11049
// 2024-01-18

#include <limits.h>

#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int dp(vector<pair<int, int> >& matrix, int size);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int> > matrix;
    for (int i = 0; i < N; ++i) {
        int r, c;
        cin >> r >> c;
        matrix.push_back(make_pair(r, c));
    }
    std::cout << dp(matrix, matrix.size());
    return 0;
}

int dp(vector<pair<int, int> >& matrix, int size) {
    // // I ~ J 까지 곱했을때의 N*M 값 [0] = N | [1] = M
    // vector<vector<vector<int> > > memo_size(
    //     size, vector<vector<int> >(size, vector<int>(2)));

    // I ~ J 까지 곱했을 때의 최소 곱셈 연산의 수
    vector<vector<int> > memo_count(size, vector<int>(size, INT_MAX));

    for (int i = 0; i < size; ++i) {
        memo_count[i][i] = 0;
    }

    // 구역 범위 지정
    for (int len = 2; len <= size; ++len) {
        // 시작 index 지정
        for (int start = 0; start <= size - len; ++start) {
            int end = start + len - 1;  // 끝 index 지정
                                        // 각 index에서 가능한 모든 조합 고려
            for (int k = start; k < end; ++k) {
                int cost =
                    memo_count[start][k] + memo_count[k + 1][end] +
                    matrix[start].first * matrix[k].second * matrix[end].second;
                memo_count[start][end] = min(cost, memo_count[start][end]);
            }
        }
    }

    return memo_count[0][size - 1];
}