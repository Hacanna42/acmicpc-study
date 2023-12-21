// 백준: 중앙 이동 알고리즘
// https://www.acmicpc.net/problem/2903
// 2023-12-21

// 피보나치인줄 알았는데, 피보나치가 아니다. 한 변의 길이 = (저번 변의 길이) +
// (저번 변의 길이 -1) 이다.

#include <iostream>
int main() {
    int n;
    int count = 2;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        count = count + count - 1;
    }
    std::cout << count * count;
    return 0;
}