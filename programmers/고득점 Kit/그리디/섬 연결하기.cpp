#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getParent(vector<int> &parents, int x) {
    if (parents[x] == x)
        return x;
    return parents[x] = getParent(parents, parents[x]);
}

void unionParent(vector<int> &parents, vector<int> &rank, int a, int b) {
    a = getParent(parents, a);
    b = getParent(parents, b);
    if (rank[a] > rank[b])
        parents[b] = a;
    else if (rank[a] < rank[b])
        parents[a] = b;
    else {
        parents[b] = a;
        rank[a] += 1;
    }
}

bool findParent(vector<int> &parents, int a, int b) {
    a = getParent(parents, a);
    b = getParent(parents, b);
    return a == b;
}

int solution(int n, vector<vector<int>> costs) {
    // Union-find
    int answer = 0;
    vector<int> parents(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }

    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });

    for (int i = 0; i < costs.size(); ++i) {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        if (!findParent(parents, a, b)) {
            unionParent(parents, rank, a, b);
            answer += cost;
        }
    }

    return answer;
}