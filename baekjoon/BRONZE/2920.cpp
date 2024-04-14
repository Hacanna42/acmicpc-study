// 백준: 2920
// https://www.acmicpc.net/problem/2920
// 2024-04-14

#include <iostream>
#include <string>
using namespace std;

int main() {
    string t;
    getline(cin, t);
    if (t == "1 2 3 4 5 6 7 8")
        cout << "ascending";
    else if (t == "8 7 6 5 4 3 2 1")
        cout << "descending";
    else
        cout << "mixed";
    return 0;
}