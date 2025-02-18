// 백준: 터렛
// https://www.acmicpc.net/problem/1002
// 2025-02-18

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int t1_x, t1_y, t1_dist;
        int t2_x, t2_y, t2_dist;
        cin >> t1_x >> t1_y >> t1_dist >> t2_x >> t2_y >> t2_dist;

        // 1. 원이 완전히 겹침
        // 양쪽 터렛의 x, y 좌표가 똑같고, dist도 똑같음
        if (t1_x == t2_x && t1_y == t2_y && t1_dist == t2_dist) {
            cout << "-1\n";
            continue;
        }

        // 2. 원이 딱 1회 만남
        // dist가 1회 만날 때 (원이 딱 1회 만남)
        int a_dist = abs(t1_x - t2_x);
        int b_dist = abs(t1_y - t2_y);
        double expected_c_dist = sqrt(pow(a_dist, 2) + pow(b_dist, 2));

        if (expected_c_dist == t1_dist + t2_dist) {
            cout << "1\n";
            continue;
        }

        // 3. 원 안에 원이 포함됨
        // 원 중심의 좌표차 + (반지름이 작은)원의 반지름이, (반지름이 큰)다른 원의 반지름보다 작다면
        int min_dist = min(t1_dist, t2_dist);
        int max_dist = max(t1_dist, t2_dist);
        if (expected_c_dist + min_dist < max_dist) {
            cout << "0\n";
            continue;
        }

        // 4. 원이 아예 따로있음
        // 원 중심의 좌표차 > 원1 반지름 + 원2 반지름
        if (expected_c_dist > t1_dist + t2_dist) {
            cout << "0\n";
            continue;
        }

        // 5. 원 안에 원이 포함되면서 딱 한번 만남
        if (expected_c_dist + min_dist == max_dist) {
            cout << "1\n";
            continue;
        }

        cout << "2\n";
        continue;
    }

    return 0;
}