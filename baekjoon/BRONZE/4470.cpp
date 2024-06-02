// 백준: 줄번호
// https://www.acmicpc.net/problem/4470
// 2024-06-02

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; ++i) {
        string s;
        getline(cin, s);
        printf("%d. %s\n", i, s.c_str());
    }
    return 0;
}