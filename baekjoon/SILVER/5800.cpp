// 백준: 성적 통계
// https://www.acmicpc.net/problem/5800
// 2024-07-26

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int K;
    cin >> K;
    for (int i = 1; i <= K; ++i) {
        int N;
        cin >> N;
        vector<int> scores;
        for (int j = 0; j < N; ++j) {
            int t;
            cin >> t;
            scores.push_back(t);
        }

        sort(scores.begin(), scores.end(), greater<int>());
        int prev = scores[0];
        int largest_gap = 0;
        for (const int next : scores) {
            largest_gap = max(largest_gap, prev - next);
            prev = next;
        }
        // print
        cout << "Class " << i << "\n";
        cout << "Max " << scores[0] << ", Min " << scores[scores.size() - 1] << ", Largest gap " << largest_gap << "\n";
    }
    return 0;
}