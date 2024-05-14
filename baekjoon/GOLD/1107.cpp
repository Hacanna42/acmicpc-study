// 백준: 리모컨
// https://www.acmicpc.net/problem/1107
// 2024-05-10

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isValidChannel(const string &channel, const vector<int> disabled) {
    for (char c : channel) {
        if (find(disabled.begin(), disabled.end(), c - '0') != disabled.end())
            return false;
    }
    return true;
}

int find_closest_channel(int target, const vector<int> &disabled_buttons) {
    int minPress = abs(target - 100);
    if (disabled_buttons.size() == 10) // 모든 버튼 X
        return minPress;

    for (int num = 0; num <= 999999; num++) {
        string str_num = to_string(num);
        if (isValidChannel(str_num, disabled_buttons)) {
            int pressCount = str_num.length() + abs(num - target);
            minPress = min(minPress, pressCount);
        }
    }

    return minPress;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int target_channel, M;
    vector<int> disabled_buttons;
    cin >> target_channel >> M;
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        disabled_buttons.push_back(t);
    }

    cout << find_closest_channel(target_channel, disabled_buttons);
    return 0;
}