// 백준: 다이얼
// https://www.acmicpc.net/problem/5622
// 2023-12-19

#include <iostream>
#include <string>

int getPhoneNum(char temp) {
    int ascii_num = temp - 65;
    // 0 1 2 | 2
    // 3 4 5 | 3
    // 6 7 8 | 4
    // 9 10 11 | 5
    // 12 13 14 | 6
    // 15 16 17 18 | 7
    // 19 20 21 | 8
    // 22 23 24 25 | 9
    if (ascii_num <= 2)
        return 2;
    else if (ascii_num <= 5)
        return 3;
    else if (ascii_num <= 8)
        return 4;
    else if (ascii_num <= 11)
        return 5;
    else if (ascii_num <= 14)
        return 6;
    else if (ascii_num <= 18)
        return 7;
    else if (ascii_num <= 21)
        return 8;
    else
        return 9;
}

int main() {
    // n + 1만큼 시간이 더 걸린다.
    // 1. 단어 입력받으면서 ASCII 이용해서 대응 숫자로 변환 저장 (char로 처리 시
    // EOF 필요, std::string으로 처리 시 필요없음)
    // 2. 반복문으로 계산

    // * 첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 단어의 길이는 2보다
    // 크거나 같고, 15보다 작거나 같다.
    std::string word;
    std::cin >> word;
    int time = 0;

    for (char c : word) {
        time += getPhoneNum(c) + 1;
    }

    std::cout << time;
    return 0;
}