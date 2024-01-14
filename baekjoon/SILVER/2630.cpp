// 백준: 색종이 만들기
// https://www.acmicpc.net/problem/2630
// 2024-01-14

#include <iostream>
#include <vector>

int white = 0, black = 0;

void divideandconquer(std::vector<std::vector<int> >& paper, int size, int x,
                      int y);
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int size;
    std::cin >> size;
    std::vector<std::vector<int> > paper(size + 1, std::vector<int>(size + 1));

    // 종이 입력
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            std::cin >> paper[i][j];
        }
    }

    // Divide and Conquer
    divideandconquer(paper, size, 1, 1);
    std::cout << white << "\n" << black;
    return 0;
}

void divideandconquer(std::vector<std::vector<int> >& paper, int size, int x,
                      int y) {
    bool same = true;
    int color = paper[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != color) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (color == 0)
            white++;
        else
            black++;
    } else {
        int newSize = size / 2;
        divideandconquer(paper, newSize, x, y);
        divideandconquer(paper, newSize, x + newSize, y);
        divideandconquer(paper, newSize, x, y + newSize);
        divideandconquer(paper, newSize, x + newSize, y + newSize);
    }
}