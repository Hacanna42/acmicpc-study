// 백준: 쿼드트리
// https://www.acmicpc.net/problem/1992
// 2024-01-14

/*
2D 이미지를 처리하면서 인덱스의 X, Y좌표에 유의.
*/
#include <iostream>
#include <string>
#include <vector>

std::string answer;
int original_size;

void divideandconquer(std::vector<std::vector<int> >& image, int size, int x,
                      int y);
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    original_size = N;
    std::cin.ignore();
    std::vector<std::vector<int> > image(N + 1, std::vector<int>(N + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            char ch = std::cin.get();
            image[i][j] = ch - '0';
        }
        std::cin.ignore();
    }

    divideandconquer(image, N, 1, 1);
    std::cout << answer;
    return 0;
}

void divideandconquer(std::vector<std::vector<int> >& image, int size, int x,
                      int y) {
    bool same = true;
    int color = image[y][x];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (image[j][i] != color) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        answer += (color == 0) ? "0" : "1";
    } else {
        answer += "(";
        int newSize = size / 2;
        divideandconquer(image, newSize, x, y);
        divideandconquer(image, newSize, x + newSize, y);
        divideandconquer(image, newSize, x, y + newSize);
        divideandconquer(image, newSize, x + newSize, y + newSize);
        answer += ")";
    }
}