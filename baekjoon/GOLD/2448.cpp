// 백준: 별 찍기 - 11
// 2024-05-23
// https://www.acmicpc.net/problem/2448

/*
Divide and Conquer
으아아아아아악

빈 벡터 공간을 공백으로 채워놓고 그리자는 생각을 하기 전까진, 접근 하기도 힘들었다.
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> output;

void draw(int r, int c) {
    output[r][c] = '*';
    output[r + 1][c - 1] = '*';
    output[r + 1][c + 1] = '*';
    output[r + 2][c - 2] = '*';
    output[r + 2][c - 1] = '*';
    output[r + 2][c] = '*';
    output[r + 2][c + 1] = '*';
    output[r + 2][c + 2] = '*';
}

void solution(int len, int r, int c) {
    if (len == 3) {
        draw(r, c);
        return;
    }

    solution(len / 2, r, c);                     // 윗 부분
    solution(len / 2, r + len / 2, c - len / 2); // 왼쪽 부분
    solution(len / 2, r + len / 2, c + len / 2); // 오른쪽 부분
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    int N;
    cin >> N;
    output.assign(N, vector<char>(N * 2 - 1, ' '));

    solution(N, 0, N - 1);

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N * 2 - 1; ++c) {
            cout << output[r][c];
        }
        cout << "\n";
    }

    return 0;
}