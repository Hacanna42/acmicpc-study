// 백준: 상범이의 우울
// https://www.acmicpc.net/problem/2811
// 2024-02-02
// 업랜디

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> feelings;
    std::vector<int> feelings_streak(N, 0);  // 연속된 우울 기간을 정리하는 벡터
    std::vector<bool> flower_days(N, false);
    int max_streak = 0;  // 최장 우울 기간을 저장하는 벡터

    // 상범이 기분 정보 입력
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        feelings.push_back(temp);
    }

    // 연속된 음수를 feelings_streak에 카운트
    for (int i = N - 1; i >= 0; --i) {
        if (feelings[i] < 0) {
            if (i != N - 1)
                feelings_streak[i] = feelings_streak[i + 1] + 1;
            else
                feelings_streak[i] = 1;

            if (feelings_streak[i] > max_streak)
                max_streak = feelings_streak[i];
        }
    }

    int max_streak_count = 0;  // 최장 우울 기간이 유일한지 판단하기 위한 변수
    // 음수 -> 양수로 넘어갈 때(우울 기간이 시작될 때) 기간 *2 만큼 꽃 선물
    for (int i = N - 1; i >= 0; --i) {
        if (feelings[i] >= 0) {  // 현재 기분이 양수라면
            if (i + 1 < N) {     // Index Valid Check
                int streak_count = feelings_streak[i + 1];
                for (int j = 0; j < streak_count * 2; ++j) {
                    if (i - j >= 0)  // Index Valid Check
                        flower_days[i - j] = true;
                }
            }
        }
        // 최장 우울 기간 유일 판단
        if (feelings_streak[i] == max_streak) max_streak_count++;
    }

    int current_flowers = 0;  // 2T 까지의 꽃 개수를 추적하기 위함
    for (int i = 0; i < N; ++i) {
        if (flower_days[i]) current_flowers++;
    }

    int answer = current_flowers;

    // 최장 기간에 대해, 3T를 적용
    for (int i = N - 1; i >= 0; --i) {
        int new_flowers_on_this_case = 0;
        if (i + 1 < N && feelings_streak[i + 1] == max_streak) {
            for (int j = 0; j < max_streak * 3; ++j) {
                if (i - j >= 0) {  // Index Valid Check
                    if (!flower_days[i - j])
                        new_flowers_on_this_case++;  // 3T로 인해 새로
                                                     // 생기는 꽃의 개수를
                                                     // 업데이트
                    // flower_days[i - j] = true;
                }
            }
            answer =
                std::max(answer, current_flowers + new_flowers_on_this_case);
        }
    }

    // // 아래 코드는 생각해보니 필요가 없다.
    // 만약 최장 우울 기간이 유일하지 않다면
    // else if (max_streak_count > 1) {
    //     for (int i = N - 1; i >= 0; --i) {
    //         if (i + 1 < N && feelings_streak[i + 1] == max_streak) {
    //         }
    //     }
    // }

    // 디버깅
    // for (int next : flower_days) {
    //     std::cout << next << " ";
    // }

    std::cout << answer;

    return 0;
}