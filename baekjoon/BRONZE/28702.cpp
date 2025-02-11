// 백준: FizzBuzz
// https://www.acmicpc.net/problem/28702
// 2025-02-11

/* 3의 배수도 아니고 5의 배수도 아닌 i가 3개 연속으로 나올 수 있는가?
수학적인 증명은 못하겠지만 딱 봐도 아닌 것 같다.
그러면 3개의 문자열 입력 중 하나는 무조건 숫자일 것 아닌가?
그러면 그 숫자에서부터 남은 입력 개수를 더해서 다음에 올 문자열을 유추해보자.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int number = 0;
    for (int i = 3; i > 0; --i) {
        string s;
        cin >> s;
        if (s == "FizzBuzz" || s == "Fizz" || s == "Buzz")
            continue;
        number = stoi(s) + i;
    }

    if (number % 3 == 0 && number % 5 == 0) {
        cout << "FizzBuzz";
        return 0;
    }
    if (number % 3 == 0 && number % 5 != 0) {
        cout << "Fizz";
        return 0;
    }
    if (number % 3 != 0 && number % 5 == 0) {
        cout << "Buzz";
        return 0;
    }

    cout << number;
    return 0;
}