// 백준: 크로아티아 알파벳
// https://www.acmicpc.net/problem/2941
// 2023-12-20

// 로직 설계
// std::string으로 line 입력받기.
// for 반복문을 사용하여 문자열을 순회합니다. 반복문 내에서 현재 문자(line[i])와
// 다음 문자(line[i+1])를 검사합니다. 크로아티아 알파벳에 해당하는 경우 (예: c=,
// dž 등)를 찾습니다. 해당하는 경우, 카운트를 1 증가시키고, 인덱스 i를 추가로
// 증가시켜 다음 문자를 건너뜁니다. 크로아티아 알파벳에 해당하지 않는 경우,
// 카운트를 1 증가시킵니다. 최종 카운트 값을 출력합니다.

#include <iostream>
#include <string>
int main() {
    std::string line;
    std::cin >> line;
    int count = 0;
    for (int i = 0; i < line.size(); i++) {
        if (i + 1 < line.length()) {
            // c=, c- 검사
            if (line[i] == 'c') {
                if (line[i + 1] == '=' || line[i + 1] == '-') {
                    i++;
                    count++;
                } else
                    count++;
            }
            // d- 검사
            else if (line[i] == 'd' && line[i + 1] == '-') {
                i++;
                count++;
            }
            // lj 검사
            else if (line[i] == 'l' && line[i + 1] == 'j') {
                i++;
                count++;
            }
            // nj 검사
            else if (line[i] == 'n' && line[i + 1] == 'j') {
                i++;
                count++;
            }
            // s= 검사
            else if (line[i] == 's' && line[i + 1] == '=') {
                i++;
                count++;
            }
            // z= 검사
            else if (line[i] == 'z' && line[i + 1] == '=') {
                i++;
                count++;
            }
            // 	dz= 검사
            else if (i + 2 < line.length() && line[i] == 'd' &&
                     line[i + 1] == 'z' && line[i + 2] == '=') {
                i += 2;
                count++;
            } else
                count++;
        } else
            count++;
    }
    std::cout << count;
    return 0;
}

// line[i+1]을 검사해서 =이 있으면 if 거는 식으로 했으면 좀 더 빠르게 할 수
// 있었을 듯.