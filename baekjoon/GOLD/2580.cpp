// 백준: 스도쿠
// https://www.acmicpc.net/problem/2580
// 2024-01-08

#include <iostream>
#include <vector>

std::vector<std::vector<int> > board(9, std::vector<int>(9));
bool solved = false;

bool check(int col, int row) {
    // 같은 행 중복 체크
    for (int i = 0; i < 9; ++i) {
        if (row != i && board[col][row] == board[col][i]) return false;
    }
    // 같은 열 중복 체크
    for (int i = 0; i < 9; ++i) {
        if (col != i && board[col][row] == board[i][row]) return false;
    }

    int squarePickerCol = col / 3;
    int squarePickerRow = row / 3;
    // 스퀘어 중복 체크
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i / 3 == squarePickerCol && j / 3 == squarePickerRow) {
                if (!(col == i && row == j) && board[col][row] == board[i][j])
                    return false;
            }
        }
    }
    return true;
}

void dfs(int L, int i) {
    if (solved) return;
    if (L == 9) {
        solved = true;
        return;
    }

    if (board[L][i] == 0) {
        // 비어있다면 그 값을 1~9까지 바꿔보기
        for (int j = 1; j <= 9; ++j) {
            board[L][i] = j;
            if (check(L, i)) {
                // 만약 넣어본 값이 올바르면
                if (i == 8)
                    dfs(L + 1, 0);
                else
                    dfs(L, i + 1);
            }
            if (solved) return;
        }
        board[L][i] = 0;  // 답이 안나오면 백트래킹
        return;
    } else {
        if (i == 8)
            dfs(L + 1, 0);
        else
            dfs(L, i + 1);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 입력
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int temp;
            std::cin >> temp;
            board[i][j] = temp;
        }
    }

    // DFS
    dfs(0, 0);

    // 출력
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}