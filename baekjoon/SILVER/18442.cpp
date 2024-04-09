// 백준: 우체국 1
// https://www.acmicpc.net/problem/18442
// 2024-04-09
// 복습 2회차 - 실력 다지기..

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> town;
vector<ll> best_comb;
ll known_shortest_distance = LLONG_MAX;
ll V, P, L; // 마을 개수, 우체국 개수, 총 길이

ll getDistances(vector<ll> &town, vector<ll> &postOffices) {
    ll sum_distance = 0;
    for (size_t i = 0; i < town.size(); ++i) {
        ll cur_pos = town[i];
        ll known_shortest = LLONG_MAX;
        for (size_t j = 0; j < postOffices.size(); ++j) {
            ll cur_compare = postOffices[j];
            ll dist = min(abs(cur_pos - cur_compare), L - abs(cur_pos - cur_compare));
            if (dist < known_shortest) {
                known_shortest = dist;
            }
        }
        sum_distance += known_shortest;
    }

    return sum_distance;
}

void dfs(ll start, ll depth, vector<ll> &postOffices) {
    if (depth == P) {
        ll dist = getDistances(town, postOffices);
        if (dist < known_shortest_distance) {
            best_comb = postOffices;
            known_shortest_distance = dist;
        }
        return;
    }

    for (ll i = start; i < V; ++i) {
        postOffices.push_back(town[i]);
        dfs(i + 1, depth + 1, postOffices);
        postOffices.pop_back(); // 백트래킹
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> P >> L;
    town.assign(V, 0);
    for (ll i = 0; i < V; ++i) {
        cin >> town[i];
    }

    vector<ll> postOffices;
    dfs(0, 0, postOffices);

    cout << known_shortest_distance << "\n";
    for (const auto next : best_comb) {
        cout << next << " ";
    }
    return 0;
}