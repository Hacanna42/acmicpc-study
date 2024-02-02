// 백준
// https://www.acmicpc.net/problem/1358
// 2024-02-02

#include <cmath>
#include <iostream>
int W, H, X, Y, P;

bool check(int px, int py) {
    double circle1_pow_x = std::pow(px - X, 2);
    double circle1_pow_y = std::pow(py - (Y + H / 2.0), 2);
    double circle2_pow_x = std::pow(px - (X + W), 2);
    double circle2_pow_y = std::pow(py - (Y + H / 2.0), 2);
    double radius_pow = std::pow(H / 2.0, 2);

    // 원 체크
    if (circle1_pow_x + circle1_pow_y <= radius_pow)
        return true;
    else if (circle2_pow_x + circle2_pow_y <= radius_pow)
        return true;

    // 직사각형 체크
    if (px >= X && px <= X + W && py >= Y && py <= Y + H) return true;

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> W >> H >> X >> Y >> P;
    int count = 0;
    for (int i = 0; i < P; ++i) {
        int player_x, player_y;
        std::cin >> player_x >> player_y;
        if (check(player_x, player_y)) count++;
    }

    std::cout << count;
    return 0;
}