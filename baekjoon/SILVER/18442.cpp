// 우체국 1
// https://www.acmicpc.net/problem/18442
// 2024-04-08

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
typedef long long ll;

ll V, P, L; // 마을 개수, 우체국 개수, 길의 길이
vector<ll> town;
ll known_min = LLONG_MAX;
vector<ll> best_comb;

ll calculateDistance(const vector<ll> &postOffices) {
    ll totalDistance = 0;
    for (int i = 0; i < V; ++i) {
        ll minDistance = LLONG_MAX;
        for (int j = 0; j < postOffices.size(); ++j) {
            ll distance = min(abs(town[i] - postOffices[j]), L - abs(town[i] - postOffices[j]));
            minDistance = min(minDistance, distance);
        }
        totalDistance += minDistance;
    }
    return totalDistance;
}

void dfs(int start, int depth, vector<ll> &postOffices) {
    if (depth == P) {
        ll currentDistance = calculateDistance(postOffices);
        if (currentDistance < known_min) {
            known_min = currentDistance;
            best_comb = postOffices;
        }
        return;
    }

    for (int i = start; i < V; ++i) {
        postOffices.push_back(town[i]);
        dfs(i + 1, depth + 1, postOffices);
        postOffices.pop_back(); // 백트래킹
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> P >> L;
    town.resize(V);
    for (int i = 0; i < V; ++i) {
        cin >> town[i];
    }

    vector<ll> postOffices;
    dfs(0, 0, postOffices);

    cout << known_min << "\n";
    for (const auto next : best_comb) {
        cout << next << " ";
    }
    return 0;
}