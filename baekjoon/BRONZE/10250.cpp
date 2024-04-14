// 백준: ACM 호텔
// https://www.acmicpc.net/problem/10250
// 2024-04-14
// Solved.ac CLASS 1 금장 도전

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;
        int count = 0;
        bool done = false;
        for (int w = 1; w <= W && !done; ++w) {
            for (int h = 1; h <= H; ++h) {
                count++;
                if (count == N) {
                    cout << h;
                    if (w < 10)
                        cout << "0";
                    cout << w << "\n";
                    done = true;
                    break;
                }
            }
        }
    }
    return 0;
}