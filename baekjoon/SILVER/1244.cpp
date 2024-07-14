// 백준: 스위치 켜고 끄기
// https://www.acmicpc.net/problem/1244
// 2024-07-13

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N; // 스위치 개수
    cin >> N;
    vector<int> switches(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> switches[i];
    }

    int student_num; // 학생의 수
    cin >> student_num;
    for (int i = 0; i < student_num; ++i) {
        int sex, number;
        cin >> sex >> number;                           // 학생의 성별과 받은 숫자
        if (sex == 1) {                                 // 학생이 남자라면
            for (int j = number; j <= N; j += number) { // 배수 스위치를 반대로 설정
                if (switches[j] == 1)
                    switches[j] = 0;
                else
                    switches[j] = 1;
            }
        } else if (sex == 2) { // 학생이 여자라면
            // 최대 대칭 구간 탐색
            int l = number, r = number;
            while (true) {
                if (l - 1 < 1 || r + 1 > N)
                    break; // 범위 초과 break
                if (switches[l - 1] != switches[r + 1])
                    break; // 대칭 아닐경우 break
                --l;
                ++r; // 양쪽으로 인덱스 확장
            }
            for (int i = l; i <= r; ++i) {
                if (switches[i] == 1)
                    switches[i] = 0;
                else
                    switches[i] = 1;
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; ++i) {
        cout << switches[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }
    return 0;
}