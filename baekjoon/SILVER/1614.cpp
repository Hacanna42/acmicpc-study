// 백준: 영식이의 손가락
// https://www.acmicpc.net/problem/1614
// 2024-02-17

#include <iostream>
using namespace std;
int main() {
    long long hurt_finger, possible_count;
    std::cin >> hurt_finger >> possible_count;
    if (hurt_finger == 1)
        cout << possible_count * 8;
    else if (hurt_finger == 5)
        cout << possible_count * 8 + 4;
    else if (hurt_finger == 2)
        cout << 1 + 6 * ((possible_count + 1) / 2) + 2 * (possible_count / 2);
    else if (hurt_finger == 3)
        cout << 2 + possible_count * 4;
    else if (hurt_finger == 4)
        cout << 3 + 2 * ((possible_count + 1) / 2) + 6 * (possible_count / 2);
}