// 백준: 걷기
// https://www.acmicpc.net/problem/1459
// 2024-07-14

/*
10억개의 연산을 2초 안에.. DP여도 DFS여도 불가능
수학+그리디적 해법 같다. 

대각선으로 가는게 효율적인지, 아니면 그냥 두 블록을 지나가는게 효율적인지 판단한다
(W*2 < S) 

규칙을 찾아본 결과:
가설: x+y가 짝수면 대각선만으로 도달할 수 있다
홀수라면 무조건 1회의 직선 이동이 필요하다.

케이스 1: 만약 직선*2가 대각선보다 비용이 낮다면, 대각선을 사용할 이유가 없다. (x+y)*직선비용으로 끝.
케이스 2: 대각선이 직선 두번보다 효율적이고, 대각선의 비용이 직선 비용보다 낮아 직선을 사용할 필요가 없다면, x+y가 짝수일 때 max(x, y)만에 도달 가능하다. max(x, y)*대각선비용으로 끝.
케이스 3: 대각선이 직선 두번보다 효율적이고, 대각선의 비용이 직선 비용보다 낮아 직선을 사용할 필요가 없지만, x+y가 홀수일 때 max(x, y)-1 의 대각선 사용, 1의 직선 사용으로 가능하다.
케이스 4: 대각선이 직선 두번보다 효율적이지만, 직선 비용이 대각선의 비용보다 낮아서 직선을 사용하는게 때로 유리하다면, min(x, y)만큼 대각선 이동하고 나머지 차를 직선으로 이동한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll X, Y; // 집의 위치
    ll W, S; // 직선 가중치 W, 대각선 가중치 S
    cin >> X >> Y >> W >> S;

    // Case 1
    if (W*2 <= S) { // 대각선을 사용할 이유가 없는 경우 (직선 두번이 더 효율적이거나 동등)
        cout << (X+Y)*W;
    }
    // 대각선이 직선 두번보다 효율적인 경우:
    else {
        if (S < W) { // 직선을 사용할 필요 
            // Case 2
            if ((X + Y) % 2 == 0) { // x + y가 짝수일 때 max(x, y)만에 도달 가능
                ll m = max(X, Y);
                cout << m * S;
            }
            
            // Case 3
            else { // 홀수일 때 max(x, y)-1만큼 대각선 사용, 1의 직선 사용으로 도달 가능
                ll m = max(X, Y) - 1;
                cout << (m * S) + W;
            }
        } else { // 직선을 사용하는 게 때로 유리함
            // Case 4: min(x, y)만큼 대각선 이동하고 나머지 거리는 직선으로
            ll m = min(X, Y);
            ll left_distance = max(X, Y) - m; // 나머지 거리 계산
            cout << (m * S) + (left_distance * W);
        }
    }
    return 0;
}