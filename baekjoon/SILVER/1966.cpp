// 백준: 프린터 큐
// https://www.acmicpc.net/problem/1966
// 2024-04-14

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M; // 문서 개수 N, 목표 M
        cin >> N >> M;
        queue<pair<int, int>> q;
        for (int i = 0; i < N; ++i) {
            int priority;
            cin >> priority;
            q.push({priority, i});
        }

        int counter = 0;

        while (!q.empty()) {
            int cur_priority = q.front().first;
            int cur_index = q.front().second;
            q.pop();
            q.push({cur_priority, cur_index});
            // 자기보다 큰 것을 찾을때까지 루프
            bool flag = true;
            while (q.front().second != cur_index && flag) {
                int next_priority = q.front().first;
                int next_index = q.front().second;
                if (next_priority > cur_priority) { // 다음 큐가 자신 우선순위보다 크면 종료
                    flag = false;
                    break;
                } else { // 다음 큐가 자신 우선순위보다 작으면 뒤로 보내기
                    q.pop();
                    q.push({next_priority, next_index});
                }
            }
            if (flag) { // 한 바퀴를 돌았지만 자신보다 큰 우선순위를 찾지 못했다면
                counter++;
                q.pop();              // 출력
                if (cur_index == M) { // 목표가 출력됐다면 반환
                    cout << counter << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}