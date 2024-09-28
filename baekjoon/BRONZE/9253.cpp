// 백준: 스페셜 저지
// https://www.acmicpc.net/problem/9253
// 2024-09-27

/*
처음에 문제를 잘 못 이해했다.
부분 문자열은 문자가 연속해서 나타나야 한다.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, answer;
    getline(cin, A);
    getline(cin, B);
    getline(cin, answer);

    size_t a_pos = A.find(answer);
    size_t b_pos = B.find(answer);

    cout << ((a_pos != string::npos && b_pos != string::npos) ? "YES" : "NO");
    return 0;
}