// 듀얼 채널 VHF 무전기
// https://www.acmicpc.net/problem/16461
// 2024-02-03

/*
부동소수점 오차 주의.
*/

#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>

int freqToInt(double freq) { return static_cast<int>(std::round(freq * 1000)); }

int getButtonCount(int target_freq, int current_freq, bool isUp) {
    int pressed = 0;
    while (current_freq != target_freq) {
        // UP 버튼의 경우
        if (isUp) {
            current_freq += 20;
            if (current_freq > 146000)
                current_freq = 144000;
        }
        // DOWN 버튼의 경우
        else {
            current_freq -= 20;
            if (current_freq < 144000)
                current_freq = 146000;
        }
        pressed++;

        if (pressed > 5)
            break;
    }

    return pressed;
}

int calculate(double _freq_A, double _freq_B, char _current_channel, double _target_freq) {
    int freq_A = freqToInt(_freq_A);
    int freq_B = freqToInt(_freq_B);
    int target_freq = freqToInt(_target_freq);
    /* 경우의 수
    1. A나 B주파수가 이미 목표와 일치하는 경우: 현재 채널과 같다면 0, 아니라면 1
    반환
    2. 채널을 변경하고 UP을 하는 경우.
    3. 채널을 변경하고 DOWN을 하는 경우.
    4. 채널을 변경하지 않고 UP을 하는 경우.
    5. 채널을 변경하지 않고 DOWN을 하는 경우.
    6. 직접 입력하는 경우 (무조건 6회)
    !. 만약 abs(현재 주파수 - 목표 주파수)가 20으로 나누어떨어지지 않으면 UP/DOWN 으로는 접근 불가능 ?
    */

    // 1. 만약 이미 A, B 주파수 중 하나가 목표와 일치한다면, ch_swap_count 반환
    int ch_swap_count = (((freq_A == target_freq && _current_channel == 'B') || (freq_B == target_freq && _current_channel == 'A')) ? 1 : 0);
    if (freq_A == target_freq && freq_B == target_freq) {
        return 0;
    }
    if (freq_A == target_freq || freq_B == target_freq) {
        return ch_swap_count;
    }

    int min_count = INT_MAX; // 최소 횟수 저장

    // 현재 채널과, A/B를 눌러야만 도달할 수 있는 채널 설정
    int current_freq = (_current_channel == 'A' ? freq_A : freq_B);
    int another_freq = (_current_channel == 'A' ? freq_B : freq_A);

    // 2~5. 목표 주파수가 20으로 나누어 떨어진다면(업/다운 버튼으로 접근 가능하다면) 채널을 변경하거나 하지않고 UP/DOWN.
    min_count = std::min(min_count, getButtonCount(target_freq, current_freq, true));
    min_count = std::min(min_count, getButtonCount(target_freq, current_freq, false));
    min_count = std::min(min_count, getButtonCount(target_freq, another_freq, true) + 1);
    min_count = std::min(min_count, getButtonCount(target_freq, another_freq, false) + 1);

    min_count = std::min(min_count, 6);

    return min_count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        double freq_A, freq_B, target_freq;
        char current_channel;
        std::cin >> freq_A >> freq_B >> current_channel >> target_freq;
        std::cout << calculate(freq_A, freq_B, current_channel, target_freq) << "\n";
    }
    return 0;
}