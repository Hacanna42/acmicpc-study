// GCD LCD 연습
#include <iostream>

/*
A와 B의 GCD(최대 공약수)는 B와 A MOD B의 GCD와 같다
최소공배수 LCM은 두 수의 곱을 그들의 GCD로 나눈 값과 같다.
*/

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b);
    return 0;
}