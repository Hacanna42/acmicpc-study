// 백준: 종이의 개수
// https://www.acmicpc.net/problem/1780
// 2024-01-14

#include <iostream>
#include <vector>

int plus = 0, zero = 0, minus = 0;

void divideandconquer(std::vector<std::vector<int> >& paper, int size, int x,
                      int y);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int> > paper(N + 1, std::vector<int>(N + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            std::cin >> paper[i][j];
        }
    }

    divideandconquer(paper, N, 1, 1);
    std::cout << minus << "\n" << zero << "\n" << plus;
    return 0;
}

void divideandconquer(std::vector<std::vector<int> >& paper, int size, int x,
                      int y) {
    bool same = true;
    int color = paper[y][x];
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (color != paper[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (color == -1)
            minus++;
        else if (color == 1)
            plus++;
        else
            zero++;
    } else {
        int newSize = size / 3;
        divideandconquer(paper, newSize, x, y);
        divideandconquer(paper, newSize, x + newSize, y);
        divideandconquer(paper, newSize, x + newSize * 2, y);
        divideandconquer(paper, newSize, x, y + newSize);
        divideandconquer(paper, newSize, x, y + newSize * 2);
        divideandconquer(paper, newSize, x + newSize, y + newSize);
        divideandconquer(paper, newSize, x + newSize * 2, y + newSize);
        divideandconquer(paper, newSize, x + newSize, y + newSize * 2);
        divideandconquer(paper, newSize, x + newSize * 2, y + newSize * 2);
    }
}