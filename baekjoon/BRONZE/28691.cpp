// 백준: 정보보호학부 동아리 소개
// https://www.acmicpc.net/problem/28691
// 2024-05-12

#include <iostream>
using namespace std;

int main() {
    char t;
    cin >> t;
    if (t == 'M')
        cout << "MatKor";
    else if (t == 'W')
        cout << "WiCys";
    else if (t == 'C')
        cout << "CyKor";
    else if (t == 'A')
        cout << "AlKor";
    else if (t == '$')
        cout << "$clear";

    return 0;
}