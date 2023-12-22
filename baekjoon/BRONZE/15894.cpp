// 백준: 수학은 체육과목 입니다
// https://www.acmicpc.net/problem/15894
// 2023-12-22

/*
왼쪽 오른쪽 변은 n과 똑같음.
천장도 n과 똑같음
밑에도 n과 똑같음...

따라서 n*2 + n + n 이니까
n*4인데 ... 아 ..... int 초과구나 ................
*/
#include <iostream>
int main() {
    long long n;
    std::cin >> n;
    std::cout << n * 4;
    return 0;
}