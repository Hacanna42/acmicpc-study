// 백준: 팰린드롬
// https://www.acmicpc.net/problem/10942
// 2024-06-17

/*
DP를 이용한 문제같다.
dp[a][b] = a~b 는 팰린드롬인지 여부
그러면 일단 base case 자기자신은 무조건 팰린드롬
// 문자열 배열: 1 2 1 3 1 2 1
dp[0][0] = true (1)
dp[1][1] = true (2) ...
dp[0][1] = (str[0] == str[1])
dp[1][2] = (str[1] == str[2])
dp[0][2] = (str[0] == str[2])
dp[1][3] = (str[1] == str[3])

정리:
길이가 1인 부분 문자열은 모두 팰린드롬이다.
길이가 2인 부분 문자열은 두 문자가 같을 때 팰린드롬이다.
길이가 3이상인 부분 문자열에 대해, dp[a][b] 는 dp[a+1][b-1]이 팰린드롬이고 str[a] == str[b] 일때 팰린드롬이다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N; // 수열의 크기 N
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Generate DP table
    vector<vector<bool>> dp(N, vector<bool>(N, false));
    // CASE 1. 길이가 1인 부분 문자열은 모두 팰린드롬이다.
    for (int i = 0; i < N; ++i) {
        dp[i][i] = true;
    }
    // CASE 2. 길이가 2인 부분 문자열은 두 문자가 같을 때 팰린드롬이다.
    for (int i = 0; i < N - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    // CASE 3. 길이가 3 이상인 부분 문자열에 대해, dp[a][b] 는 dp[a+1][b-1]이 팰린드롬이고 str[a] == str[b] 일때 팰린드롬이다.
    for (int len = 2; len < N; ++len) {
        for (int i = 0; i < N - len; ++i) {
            int j = i + len;
            if (dp[i + 1][j - 1] && arr[i] == arr[j]) {
                dp[i][j] = true;
            }
        }
    }

    int M; // 질문의 개수 M
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int S, E;
        cin >> S >> E;
        cout << (dp[S - 1][E - 1] ? "1" : "0") << "\n";
    }

    return 0;
}