// 백준: 카드 게임
// https://www.acmicpc.net/problem/5522
// 2024-10-16

#include <iostream>
using namespace std;

int main() {
    long long sum = 0;
    for (int i = 0; i < 5; ++i) {
        long long input;
        cin >> input;
        sum += input;
    }

    cout << sum;
    return 0;
}