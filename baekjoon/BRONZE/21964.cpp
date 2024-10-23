// 백준: 선린인터넷고등학교 교가
// https://www.acmicpc.net/problem/21964
// 2024-10-23

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t >> s;
    for (int i = s.size() - 5; i < s.size(); ++i) {
        cout << s[i];
    }
    return 0;
}