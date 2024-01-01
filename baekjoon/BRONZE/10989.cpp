// 백준: 수 정렬하기 3
// https://www.acmicpc.net/problem/10989
// 2024-01-01

#include <algorithm>  // 감사합니다
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

/*
실행시간 출력 메모리 이런거 줄이겠다고 스트림만들고 tie하고 이런거
다 필요 없었고 그저 ... 계수 정렬 방식을 사용하면 됐었다.
*/

int main() {
    int N;
    // 실행시간 다이어트 조치
    std::ios_base::sync_with_stdio(false);  // C++과 C stdio 버퍼링 동기화 끔
    std::cin.tie(nullptr);  // 입출력간 tie 해제(입력 발생 시 출력 버퍼가
                            // 자동으로 비워지는것을 방지)
    int sort_list[10001] = {
        0,
    };
    std::ostringstream oss;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        sort_list[temp]++;
    }

    // 저장된 계수의 값만큼 출력
    for (int i = 0; i < 10001; ++i) {
        if (sort_list[i] > 0) {
            for (int j = 0; j < sort_list[i]; ++j) {
                std::cout << i << "\n";
            }
        }
    }

    return 0;
}
