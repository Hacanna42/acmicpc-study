// 백준: 카잉 달력
// https://www.acmicpc.net/problem/6064
// 2024-04-30

#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        ll max = lcm(M, N);
        int cnt = 0;
        while (true) {
            int dx = M - x;
            int dy = N - y;
            if (dx > dy) { // y가 M에 더 빨리 도달
                y = N;
                x += dy;
                cnt += dy;
            } else if (dx < dy) { // x가 N에 더 빨리 도달
                x = M;
                y += dx;
                cnt += dx;
            } else { // 동시에 도달한다면
                cnt += dx;
                cout << max - cnt << "\n";
                break; // 멸망해
            }

            if (x == M && y == N) {
                cout << max - cnt << "\n";
                break; // 멸망해
            }

            cnt++;
            x = (x % M) + 1;
            y = (y % N) + 1;

            if (cnt > max) {
                cout << "-1\n";
                break;
            }
        }
    }
}