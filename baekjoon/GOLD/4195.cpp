// 백준: 친구 네트워크
// https://www.acmicpc.net/problem/4195
// 2024-08-25

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size; // 집합 크기 추적

  public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 경로 압축
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];
            }
        }
    }

    int getSize(int x) {
        int rootX = find(x);
        return size[rootX];
    }

    // void printIndex() {
    //     for (const auto &next : parent) {
    //         cout << next << " ";
    //     }
    // }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC; // 테스트케이스의 수
    cin >> TC;
    while (TC--) {
        int F; // 친구 관계의 수 (F < 100,000)
        cin >> F;
        UnionFind uf(F * 2);
        unordered_map<string, int> map;
        int id = 1; // 친구 이름과 인덱스를 연결할 ID
        while (F--) {
            // 친구 두명 입력 받음
            string first, second;
            cin >> first >> second;
            if (map[first] == 0)
                map[first] = id++; // 처음 등장했다면 id 부여 후 increment
            if (map[second] == 0)
                map[second] = id++;

            // find 를 사용하는 것보다, [] operator를 통해 초기값인지 확인하는 방법이 더 효율적인 것 같아서 변경함.

            // if (map.find(first) == map.end()) { // 처음 등장한 친구인지 확인하고, 처음 등장했다면 ID 부여
            //     // 처음 등장했다면
            //     map[first] = id++; // 아이디를 부여하고 increment
            // }
            // if (map.find(second) == map.end()) { // 두번째 친구도 동일하게 검증
            //     map[second] = id++;
            // }

            // 친구 두명을 disjoint set 상에서 union
            uf.unionSets(map[first] - 1, map[second] - 1); // -1로 인덱스 조정

            // 친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하기
            cout << uf.getSize(map[first] - 1) << "\n";
        }
    }
    return 0;
}