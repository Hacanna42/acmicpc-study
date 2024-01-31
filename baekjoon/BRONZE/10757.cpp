// 백준: 큰수 A+B
// https://www.acmicpc.net/problem/10757
// 2024-01-31
// 업다운 디펜스 디버깅용

#include <algorithm>
#include <iostream>
#include <string>

std::string addLargeNumbers(std::string a, std::string b) {
    if (b.length() > a.length()) {
        swap(a, b);
    }

    std::string result = "";
    int n1 = a.length(), n2 = b.length();

    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sum = ((a[n1 - 1 - i] - '0') + (b[n2 - 1 - i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n2; i < n1; i++) {
        int sum = ((a[n1 - 1 - i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    std::string A, B;
    std::cin >> A >> B;

    std::string sum = addLargeNumbers(A, B);
    std::cout << sum << "\n";

    return 0;
}
