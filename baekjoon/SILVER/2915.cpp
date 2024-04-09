// 백준: 로마 숫자 재배치
// https://www.acmicpc.net/problem/2915
// 2024-04-09

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string roman_units[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; // 1 ~ 9
string roman_tens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};  // 1* ~ 9*
int smallest_num = (~0U >> 2);
string smallest_roman;

bool search(string text, string compare, int start, int l) {
    string new_text = text.substr(start, l);
    if (new_text.length() != compare.length())
        return false;
    for (int i = 0; i < new_text.length(); ++i) {
        if (new_text[i] != compare[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string B;
    cin >> B;
    sort(B.begin(), B.end());
    do {
        // 십의 자리
        for (int i = 0; i < 9; ++i) {
            int index = 0;
            if (search(B, roman_tens[i], index, roman_tens[i].length())) {
                index += roman_tens[i].length();
                for (int j = 0; j < 9; ++j) {
                    if (search(B, roman_units[j], index, roman_units[j].length())) {
                        int temp = (i + 1) * 10;
                        temp += j + 1;

                        if (temp < smallest_num && roman_tens[i].length() + roman_units[j].length() == B.length()) {
                            smallest_num = temp;
                            smallest_roman = roman_tens[i] + roman_units[j];
                        }
                    }
                }
            }
        }

        // 일의 자리
        for (int j = 0; j < 9; ++j) {
            int index = 0;
            if (search(B, roman_units[j], index, roman_units[j].length())) {
                if (j + 1 < smallest_num && roman_units[j].length() == B.length()) {
                    smallest_num = j + 1;
                    smallest_roman = roman_units[j];
                }
            }
        }

    } while (next_permutation(B.begin(), B.end()));

    cout << smallest_roman;
    return 0;
}