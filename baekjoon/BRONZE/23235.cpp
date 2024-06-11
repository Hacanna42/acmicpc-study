// 백준: The Fastest Sorting Algorithm In The World
// https://www.acmicpc.net/problem/23235
// 2024-06-10

#include <iostream>
#include <string>
using namespace std;
int main() {
    int i = 1;
    while (true) {
        string s;
        getline(cin, s);
        if (s == "0")
            break;
        printf("Case %d: Sorting... done!\n", i++);
    }
    return 0;
}