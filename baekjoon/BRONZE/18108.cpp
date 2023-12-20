// 백준: 1998년생인 내가 태국에서는 2541년생?!
// https://www.acmicpc.net/problem/18108
// 2023-11-24

#include <iostream>
int main() {
    int input_year = 0;
    std::cin >> input_year;
    std::cout << input_year - 543;
    return 0;
}