// 백준: solved.ac
// https://www.acmicpc.net/problem/18110
// 2024-04-24

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int round15Percent(int n) { return static_cast<int>(round(n * 0.15)); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    if (N == 0) {
        cout << "0";
        return 0;
    }

    vector<int> scores(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());
    int trim_s = round15Percent(N);
    ll sum = 0;
    for (int i = trim_s; i < N - trim_s; ++i) {
        sum += scores[i];
    }
    if (sum == 0)
        cout << "0";
    else
        cout << round(sum / static_cast<double>((N - (trim_s * 2))));
    return 0;
}