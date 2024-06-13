// 백준: 아이 러브 크로아티아
// https://www.acmicpc.net/problem/9517
// 2024-06-13

#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int K, question_num;
    int cur_time = 0;
    cin >> K >> question_num;
    for (int i = 0; i < question_num; ++i) {
        int time;
        char answer;
        cin >> time >> answer;
        cur_time += time;
        if (cur_time > 210) { // 3분 30초 경과
            break;
        }
        // 대답
        if (answer == 'T') {
            ++K; // 폭탄 넘기기
        }
    }

    cout << (K - 1) % 8 + 1;
    return 0;
}