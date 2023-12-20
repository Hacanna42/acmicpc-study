// 백준: 최댓값
// https://www.acmicpc.net/problem/2566
// 2023-12-20

// 굳이 행렬을 선언 해야되나?
// 값을 받으면서 최대값에 대한 i, j를 기록한다면 ?

#include <iostream>
int main() {
    int max_value = 0;
    int max_row = 0;
    int max_column = 0;
    for (int i = 0; i < 9; i++) {      // 행
        for (int j = 0; j < 9; j++) {  // 열
            int value;
            if (std::cin >> value && value > max_value) {
                max_value = value;
                max_row = j;
                max_column = i;
            }
        }
    }
    std::cout << max_value << std::endl << max_column + 1 << " " << max_row + 1;
    return 0;
}