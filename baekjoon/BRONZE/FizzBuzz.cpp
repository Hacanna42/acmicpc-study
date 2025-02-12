#include <iostream>
#include <string>
using namespace std;

int main() {
    int number = 0; // 순수 값
    for (int i = 3; i > 0; --i) {
        string s;
        cin >> s; // 문자열 입력받기
        if (s == "FizzBuzz" || s == "Fizz" || s == "Buzz")
            continue;
        number = stoi(s) + i; // +index 를 통해서 다음 숫자 (변환해야 할 숫자를 구함)
    }

    // 여기까지 왔으면, number은 순수한 숫자를 가지고 있는 상태임
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