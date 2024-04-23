// 백준: 덩치
// https://www.acmicpc.net/problem/7568
// 2024-04-23

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; ++i) {
        int weight, height;
        cin >> weight >> height;
        p[i] = make_pair(weight, height);
    }

    for (int i = 0; i < N; ++i) {
        int k = 0;
        int cur_weight = p[i].first;
        int cur_height = p[i].second;
        for (int j = 0; j < N; ++j) {
            if (j == i)
                continue;
            int comp_weight = p[j].first;
            int comp_height = p[j].second;
            if (cur_weight < comp_weight && cur_height < comp_height)
                k++;
        }
        cout << k + 1 << " ";
    }
    return 0;
}