// 백준: 세탁소 사장 동혁
// https://www.acmicpc.net/problem/2720
// 2023-12-21

/*
입력 n이 0이 될때까지 while: Quarter = n%25. Dime = n%10. Nickel = n%5. Penny =
나머지 n
*/
#include <iostream>
int main() {
    int testcases;
    int quarter = 0, dime = 0, nickel = 0, penny = 0;
    std::cin >> testcases;
    int n;
    for (int i = 0; i < testcases; i++) {
        std::cin >> n;
        quarter = n / 25;
        n %= 25;
        dime = n / 10;
        n %= 10;
        nickel = n / 5;
        n %= 5;
        penny = n;
        std::cout << quarter << " " << dime << " " << nickel << " " << penny
                  << std::endl;
    }
    return 0;
}