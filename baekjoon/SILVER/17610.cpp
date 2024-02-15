// 백준: 양팔저울
// https://www.acmicpc.net/problem/17610
// 2024-02-15

#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int k;
int S = 0;

set<int> combi;
vector<int> weights;
int answer = 0;

void calculate(int depth, int current) {
    if (current >= 1) {
        if (combi.find(current) == combi.end()) {
            answer++;
            combi.insert(current);
        }
    }

    if (depth == k)
        return;

    calculate(depth + 1, current + weights[depth]);
    calculate(depth + 1, current - weights[depth]);
    calculate(depth + 1, current);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k;
    weights.assign(k, 0);
    for (int i = 0; i < k; ++i) {
        cin >> weights[i];
        S += weights[i];
    }

    calculate(0, 0);

    cout << S - answer;

    return 0;
}