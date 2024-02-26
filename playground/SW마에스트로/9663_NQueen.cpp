#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> queen;

bool checkboard(int row) {
    for (int i = 0; i < row; ++i) {
        // 같은 열에 있는지 검사
        if (queen[i] == queen[row])
            return false;
        // 대각선 검사
        if (abs(queen[i] - queen[row]) == abs(i - row))
            return false;
    }
    return true;
}

int counter = 0;
void dfs(int depth) {
    if (depth == N) {
        counter++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        queen[depth] = i;
        if (checkboard(depth))
            dfs(depth + 1);
        queen[depth] = -1;
    }
}

int main() {
    cin >> N;
    queen.assign(N, -1);
    dfs(0);
    cout << counter;
    return 0;
}