// 백준: 삼각형
// https://www.acmicpc.net/problem/29751
// 2024-08-24

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int W, H;
    cin >> W >> H;
    cout << fixed << setprecision(1) << double(W * H) / 2;
    return 0;
}