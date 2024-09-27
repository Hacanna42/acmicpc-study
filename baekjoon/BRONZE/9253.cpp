// 백준: 스페셜 저지
// https://www.acmicpc.net/problem/9253
// 2024-09-27

#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, answer;
    getline(cin, A);
    getline(cin, B);
    getline(cin, answer);

    int SIZE = answer.size();
    for (int i = 0; i < SIZE; ++i) {
        size_t a_pos = A.find(answer[i]);
        size_t b_pos = B.find(answer[i]);
        if (a_pos != string::npos && b_pos != string::npos) { // 둘다 값이 있는지 확인
            A = A.substr(a_pos + 1);                          // 찾은 문자열부터 시작하도록 잘라내기
            B = B.substr(b_pos + 1);                          // 이거 너무 비용이 많이 든다
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}