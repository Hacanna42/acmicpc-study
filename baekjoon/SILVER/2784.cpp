// 백준: 가로 세로 퍼즐
// https://www.acmicpc.net/problem/2784
// 2024-02-22

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> str(6);
map<string, int> str_list;

bool check(vector<string> &info) {
    map<string, int> visited;
    int n = info.size();

    // 가로 조사
    for (int r = 0; r < n; ++r) {
        string temp = info[r];
        auto it = find(str.begin(), str.end(), temp);
        if (it != str.end()) {
            visited[temp] += 1;
        } else {
            return false;
        }
    }

    // 세로 조사
    for (int c = 0; c < n; ++c) {
        string temp = "";
        for (int r = 0; r < n; ++r) {
            temp += info[r][c];
        }
        auto it = find(str.begin(), str.end(), temp);
        if (it != str.end()) {
            visited[temp] += 1;
        } else {
            return false;
        }
    }

    return str_list == visited;
}

bool generateAndCheck(vector<string> &current, vector<bool> &used, int depth) {
    if (depth == 3) {
        return check(current);
    }

    for (int i = 0; i < 6; ++i) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(str[i]);

            if (generateAndCheck(current, used, depth + 1)) {
                return true;
            }

            current.pop_back();
            used[i] = false;
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < 6; ++i) {
        cin >> str[i];
        str_list[str[i]] += 1;
    }

    vector<string> current;
    vector<bool> used(6, false);
    if (generateAndCheck(current, used, 0)) {
        for (const auto &word : current) {
            cout << word << "\n";
        }
    } else {
        cout << "0";
    }

    return 0;
}