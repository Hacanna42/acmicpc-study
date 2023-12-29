// 백준: 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018
// 2023-12-29

/*
중간에 한번의 발상의 전환이 필요한 문제였다.
주변으로 8*8 공간이 있는 위치를 찾은 뒤, 몇개의 칸이 오답인지 카운트하면 된다.
체스판을 90도 돌리면 흑백 패턴이 완전히 반대로 되는데, 체스판이 꼭 주어진 입력과
같은 방향으로 놓여 있어야 한다는 조건은 없었으므로 몇개의 칸이 답인지도 카운트
하고 오답과 답 개수중에 가장 작은 값을 답으로 하면 된다
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    int m, n;
    int answer = 0;
    std::string board_temp;
    std::vector<std::string> board;
    int min_counter = 64;
    std::cin >> m >> n;
    std::cin.ignore();
    for (int i = 0; i < m; ++i) {
        std::getline(std::cin, board_temp);
        board.push_back(board_temp);
    }
    for (int height = 0; height < m; ++height) {
        for (int width = 0; width < n; ++width) {
            if (width + 8 <= n && height + 8 <= m) {
                // 8*8 공간이 있는 위치
                bool iswhite = true;
                int counter = 0;
                int reverse_counter = 0;
                for (int h_pointer = height; h_pointer < height + 8;
                     ++h_pointer) {
                    for (int w_pointer = width; w_pointer < width + 8;
                         ++w_pointer) {
                        if ((iswhite && board[h_pointer][w_pointer] == 'W') ||
                            (!iswhite && board[h_pointer][w_pointer] == 'B')) {
                            ++reverse_counter;
                        } else
                            ++counter;
                        iswhite = !iswhite;
                    }
                    iswhite = !iswhite;
                }
                if (counter < min_counter) {
                    min_counter = counter;
                }
                if (reverse_counter < min_counter) {
                    min_counter = reverse_counter;
                }
            }
        }
    }
    std::cout << min_counter << std::endl;
    return 0;
}