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
    size_t a_pos = 0;
    size_t b_pos = 0;

    for (int i = 0; i < SIZE; ++i) {
        a_pos = A.find(answer[i], a_pos);
        b_pos = B.find(answer[i], b_pos);
        if (a_pos == string::npos || b_pos == string::npos) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}