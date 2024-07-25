// 백준: 스위치와 램프
// https://www.acmicpc.net/problem/16960
// 2024-07-21

/*
모든 스위치를 누르면 모든 램프가 켜지는 입력만 주어진다.
즉, 하나의 스위치를 빼도 지장이 없는지를 파악해야 한다.

입력 제한이 N, M <= 2000. 브루트포스로 가능할 것 같다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; // 스위치의 수 N
    int M; // 램프의 수 M
    cin >> N >> M; 
    // 1-based index
    vector<vector<int>> switch_info(N+1, vector<int>());
    for (int i=1;i<=N;++i) { // 스위치 정보 입력
       int conn_cnt; // 연결된 램프 수
       cin >> conn_cnt;
       for (int j=0;j<conn_cnt;++j) {
            int lamp;
            cin >> lamp;
            switch_info[i].push_back(lamp);
       }
    }

    for (int except=1;except<=N;++except) {
        vector<bool> lamp_status(M+1, false);
        for (int i=1;i<=N;++i) {
            if (i == except) continue;
            for (const auto& lamp : switch_info[i]) {
                lamp_status[lamp] = true;
            }
        }

        // lamp check
        bool pass = true;
        for (int i=1;i<=M;++i) {
            if (!lamp_status[i]) {
                pass = false;
                break;
            }
        }

        if (pass) {
            cout << "1";
            return 0;
        }
    }

    cout << "0";
    return 0;
}