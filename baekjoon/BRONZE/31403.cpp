// 백준: A + B - C
// https://www.acmicpc.net/problem/31403
// 2024-08-30
// BJCORD 웹훅 테스트

#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << A + B - C << "\n";
    cout << stoi(to_string(A) + to_string(B)) - C;
    return 0;
}