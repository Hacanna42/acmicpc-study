// 백준: 가장 긴 감소하는 부분 수열
// https://www.acmicpc.net/problem/11722
// 2024-02-14

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> lis(N + 1, 1);
    vector<int> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    for (int i = v.size() - 1; i > 0; --i) {
        for (int j = v.size() - 1; j > i; --j) {
            if (v[i] > v[j])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    cout << *max_element(lis.begin(), lis.end());
    return 0;
}