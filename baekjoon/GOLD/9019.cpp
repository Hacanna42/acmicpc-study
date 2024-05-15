// 백준: DSLR
// https://www.acmicpc.net/problem/9019
// 2024-05-15

/* 추론 과정:
제일 naive하게 떠오른 방법: 재귀 + 약간 DP로 탐색하기
근데 사실상 위의 방법이 재귀로 DFS 구현한 거랑 똑같음 (Recursive DFS)
모든 해를 탐색하고 결과를 내는 것보다, queue로 BFS 탐색을 하면 훨씬 빠르겠다!
BFS 특성: dp[B]에 도달한 첫 루트가 최단거리임을 활용하자.

문자열 연산(string)의 비용이 매우 높다는 걸 뼈저리게 느낀 문제.
메모리 할당/해제가 반복되면서 자꾸 TLE가 나는 거 같다..
L과 R을 string으로 구현한 게 문제였다.. 으악

교육적이다
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
    int n;
    int depth;
    string command;
};

int D(const int &n) { return (n * 2) % 10000; }

int S(const int &n) {
    if (n == 0)
        return 9999;
    else
        return n - 1;
}

int L(int n) { return (n % 1000) * 10 + (n / 1000); }

int R(int n) { return (n / 10) + (n % 10) * 1000; }

// int L(const int &n) {
//     string s = to_string(n);
//     char t = s.front();
//     s.erase(s.begin());
//     s.push_back(t);
//     return stoi(s);
// }

// int R(const int &n) {
//     string s = to_string(n);
//     char t = s.back();
//     s.pop_back();
//     s.insert(s.begin(), t);
//     return stoi(s);
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int A, B;
        cin >> A >> B;
        queue<node> q;
        vector<bool> visited(10000, false);
        q.push({A, 0, ""}); // 현재 수 N, 깊이 0, 커맨드 ""
        visited[A] = true;  // 시작 노드 방문 체크

        while (!q.empty()) {
            int cur_n = q.front().n;
            int cur_depth = q.front().depth;
            string cur_command = q.front().command;
            q.pop();
            if (cur_n == B) {
                cout << cur_command << "\n";
                break;
            }

            // BFS에서, 방문 체크는 큐를 넣을 때 해야 함. (효율성)
            int cal_d = D(cur_n);
            int cal_s = S(cur_n);
            int cal_l = L(cur_n);
            int cal_r = R(cur_n);

            if (!visited[cal_d]) {
                q.push({cal_d, cur_depth + 1, cur_command + "D"});
                visited[cal_d] = true;
            }

            if (!visited[cal_s]) {
                q.push({cal_s, cur_depth + 1, cur_command + "S"});
                visited[cal_s] = true;
            }

            if (!visited[cal_l]) {
                q.push({cal_l, cur_depth + 1, cur_command + "L"});
                visited[cal_l] = true;
            }

            if (!visited[cal_r]) {
                q.push({cal_r, cur_depth + 1, cur_command + "R"});
                visited[cal_r] = true;
            }
        }
    }
}

// 삽질 ..
// #include <iostream>
// #include <string>
// #include <utility>
// #include <vector>

// using namespace std;

/*
DP 아니야 ~~~~~~~~~~~~~~~~ 못 풀어 ~~~~~~~~
*/

// vector<pair<int, string>> dp;
// int counter;

// void solution(int &n, string command, int depth) {
//     if (dp[n].first <= depth)
//         return; // 기저조건: 이미 최적해가 있다면 리턴

//     if (counter > 100) // 최적화
//         return;

//     counter++;
//     dp[n].first = depth;
//     dp[n].second = command;

//     // D
//     int t = D(n);
//     if (dp[t].first > depth + 1) { // 최적해라면 DP 업데이트
//         solution(t, command + "D", depth + 1);
//     }

//     // S
//     t = S(n);
//     if (dp[t].first > depth + 1) { // 최적해라면 DP 업데이트
//         solution(t, command + "S", depth + 1);
//     }

//     // L
//     t = L(n);
//     if (dp[t].first > depth + 1) { // 최적해라면 DP 업데이트
//         solution(t, command + "L", depth + 1);
//     }

//     // R
//     t = R(n);
//     if (dp[t].first > depth + 1) { // 최적해라면 DP 업데이트
//         solution(t, command + "R", depth + 1);
//     }
// }

// int main() {
//     int TC;
//     cin >> TC;
//     while (TC--) {
//         int A, B;
//         cin >> A >> B;
//         dp.assign(10000, {(~0U >> 2), ""}); // 0부터 9999까지

//         // 재귀 돌리기 전에, 예측가능한 최적해는 구해놓기
//         // 1. A를 계속 D하기
//         int i = 1;
//         int t = D(A);
//         while (i < 10) {
//             if (i < dp[t].first) {
//                 dp[t].first = i;
//                 string s = "";
//                 for (int j = 0; j < i; ++j)
//                     s.push_back('D');
//                 dp[t].second = s;
//             }
//             ++i;
//             t = D(t);
//         }

//         // 2. A를 계속 빼기
//         t = S(A);
//         for (int i = 1; i <= 10000; ++i) {
//             if (i < dp[t].first) {
//                 dp[t].first = i;
//                 string s = "";
//                 for (int j = 0; j < i; ++j)
//                     s.push_back('S');
//                 dp[t].second = s;
//             }
//             t = S(t);
//         }

//         // 3. R 3번
//         t = R(A);
//         for (int i = 1; i <= 3; ++i) {
//             if (i < dp[t].first) {
//                 dp[t].first = i;
//                 string s = "";
//                 for (int j = 0; j < i; ++j)
//                     s.push_back('R');
//                 dp[t].second = s;
//             }
//             t = R(t);
//         }

//         counter = 0;
//         solution(A, "", 0);
//         cout << dp[B].second << "\n";
//     }
//     return 0;
// }