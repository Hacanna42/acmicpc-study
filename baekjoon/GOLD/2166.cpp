// 다각형의 면적
// https://www.acmicpc.net/problem/2166
// 2024-06-13

/*
신발끈 공식(shoelace formula)가 필요하다
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x;
    double y;
};

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // 신발끈의 공식
    double sum1 = 0, sum2 = 0;
    for (int i = 1; i < N; ++i) {
        sum1 += points[i - 1].x * points[i].y;
        sum2 += points[i - 1].y * points[i].x;
    }

    // 처음 좌표와 다시 묶기
    sum1 += points[0].y * points[N - 1].x;
    sum2 += points[0].x * points[N - 1].y;

    double answer = (sum1 - sum2) / 2;
    cout << fixed << setprecision(1) << abs(answer);
    return 0;
}