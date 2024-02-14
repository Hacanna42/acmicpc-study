#include <string>
#include <vector>

using namespace std;

int getParent(vector<int> &parents, int x) {
    if (parents[x] == x)
        return x;
    else
        return getParent(parents, parents[x]);
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

int solution(int n, vector<vector<int>> computers) {
    vector<int> parents(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }

    // Union 연산
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (computers[i][j] == 1 && i != j)
                unionParent(parents, rank, i, j);
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (parents[i] == i)
            answer++;
    }

    return answer;
}