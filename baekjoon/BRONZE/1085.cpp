// 백준: 직사각형에서 탈출
// https://www.acmicpc.net/problem/1085
// 2023-12-22

/*
각 x,y값에 대해 0까지의 거리와 직사각형의 x,y까지의 거리를 계산
제일 짧은 거리를 반환
*/
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
    int x, y, w, h;
    int dx, dy;
    std::vector<int> distances;
    std::cin >> x >> y >> w >> h;
    dx = abs(x - w);
    dy = abs(y - h);
    int distance = (dx < dy) ? dx : dy;
    if (distance > x || distance > y) {
        int temp = (x < y) ? x : y;
        std::cout << temp;
    } else
        std::cout << distance;
    return 0;
}