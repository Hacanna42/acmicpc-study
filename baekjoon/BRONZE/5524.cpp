// 백준: 입실 관리
// https://www.acmicpc.net/problem/5524
// 2024-11-04

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
        cout << str << "\n";
    }
    return 0;
}