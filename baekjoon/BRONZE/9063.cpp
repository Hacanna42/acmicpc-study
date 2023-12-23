// 백준: 대지
// https://www.acmicpc.net/problem/9063
// 2023-12-23

/*
모든 옥구슬 중 값이 제일 작고 큰 x y를 두개씩 구함
가장 작은 (x,y) 쌍과 가장 큰 (x,y) 쌍을 만들고 면적 계산
*/

#include <iostream>
int main() {
    int N;
    int max_x = -10000, max_y = -10000, min_x = 10000, min_y = 10000;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        if (x > max_x) max_x = x;
        if (y > max_y) max_y = y;
        if (x < min_x) min_x = x;
        if (y < min_y) min_y = y;
    }
    std::cout << (max_x - min_x) * (max_y - min_y);
    return 0;
}