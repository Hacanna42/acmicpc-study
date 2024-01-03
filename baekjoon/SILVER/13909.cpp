// 백준: 창문 닫기
// https://www.acmicpc.net/problem/13909
// 2024-01-03

#include <cmath>
#include <iostream>

/*
map을 이용해 모든 상태를 브루트포스하면 메모리 초과가 뜬다.
창문이 열리려면 그 창문 번호는 홀수개의 약수를 가져야한다.
완전 제곱수만이 홀수개의 약수를 갖는다.
또, 1부터 N까지의 완전 제곱수의 수는 루트 N의 정수 부분과 같다.
재밌는 문제...
*/
int main() {
    int N;
    std::cin >> N;
    int count = static_cast<int>(sqrt(N));
    std::cout << count;
    return 0;
}