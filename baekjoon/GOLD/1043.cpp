// 백준: 거짓말
// 2024-05-23
// https://www.acmicpc.net/problem/1043

/*
그래프 탐색 같다.
각 사람들을 노드로 두고, 같은 파티에 참여하는 사람끼리 간선을 잇는다.
진실을 알고 있는 사람과 간선이 연결되어 있다면. 어떻게든 진실을 알 수 있는 사람이다.
따라서 진실을 알고 있는 사람과 간선이 연결되어 있지 않은 사람들끼리만 이루어져있는 파티에서만 과장을 할 수 있다.

근데 문제는 간선 정보 추가할 때 파티에 참가한 사람 모두를 엮어야 되는데 이게 너무 비효율적이다.
Union-find를 사용해야 할 것 같다.

PS. Union-find를 연습할 수 있는 교육적인 문제. 높은 트리에 낮은 트리를 붙여야 트리가 너무 깊어지는 것을 막을 수 있다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> parents;
vector<int> node_rank;

// union-find
int find_root(int x) {
    if (parents[x] != x)
        parents[x] = find_root(parents[x]);
    return parents[x];
}

void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) {
        if (node_rank[x] < node_rank[y])
            parents[x] = y;
        else if (node_rank[x] > node_rank[y])
            parents[y] = x;
        else {
            parents[y] = x;
            node_rank[x]++;
        }
    }
}

int main() {
    int N, M; // 사람의 수 N, 파티의 수 M
    cin >> N >> M;

    int truthNum; // 진실을 아는 사람의 수
    cin >> truthNum;
    vector<int> truthPeople(truthNum);
    for (int i = 0; i < truthNum; ++i) {
        cin >> truthPeople[i];
    }

    parents.assign(N + 1, 0);
    node_rank.assign(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        parents[i] = i;
    }

    // 파티 입력받기
    vector<vector<int>> parties(M);
    for (int i = 0; i < M; ++i) {
        int partyNum; // 파티에 오는 사람들
        cin >> partyNum;
        parties[i].resize(partyNum);
        for (int j = 0; j < partyNum; ++j) {
            cin >> parties[i][j];
        }

        // 파티 참석자 모두 union_root
        for (int j = 1; j < partyNum; ++j) {
            union_root(parties[i][0], parties[i][j]);
        }
    }

    // 진실을 아는 사람의 루트 알아내기
    int truthRoot = -1;
    if (truthNum > 0) {
        truthRoot = find_root(truthPeople[0]);
        for (int i = 1; i < truthNum; ++i) {
            union_root(truthPeople[0], truthPeople[i]);
        }
        truthRoot = find_root(truthPeople[0]);
    }

    // 모든 파티를 순회하면서 진실을 아는 사람과 root가 같은 참석자가 없는지 체크
    int cnt = 0;
    for (const auto &party : parties) {
        bool flag = true;
        for (const auto &person : party) {
            if (find_root(person) == truthRoot) { // 진실을 아는 사람과 루트가 같다면
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }

    cout << cnt;
    return 0;
}