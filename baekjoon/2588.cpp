// 백준: 곱셈
// https://www.acmicpc.net/problem/2588
// 2023-11-24

/*
내가 생각한 문제점은, 여기서 굳이 combinator이라는 배열을 썼다는 거다.
어차피 계산된 값에 대하여 /10과 %10 연산을 통해 십의 자리 수와 일의 자리 수를
구분할 수 있는데. 굳이 combinator을 쓸 필요가 없었다 ..
그리고 어차피 문자열은 += 연산으로 앞에서부터 추가할 수 있으니까 ..
역시 문제를 풀기 전에, 실제 코드를 작성하기 전에 효율적 패턴을 찾는 게 중요하다.
*/

#include <iostream>
#include <string>

int main() {
    char first[4], second[4];
    std::cin >> second >> first;
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < 3; i++) {
        num1 = num1 * 10 + (first[i] - '0');
        num2 = num2 * 10 + (second[i] - '0');
    }

    for (int i = 0; i < 3; i++) {
        int n1 = first[2 - i] - '0';
        int carry = 0;
        std::string result = "";

        for (int j = 2; j >= 0; j--) {
            int n2 = second[j] - '0';
            int product = n1 * n2 + carry;
            carry = product / 10;
            result = char(product % 10 + '0') + result;
        }

        if (carry > 0) {
            result = char(carry + '0') + result;
        }

        // 결과 출력
        std::cout << result << std::endl;
    }
    std::cout << num1 * num2;
    return 0;
}
