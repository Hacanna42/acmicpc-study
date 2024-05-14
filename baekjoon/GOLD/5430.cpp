// 백준: AC
// https://www.acmicpc.net/problem/5430
// 2024-05-13

#include <deque>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

deque<int> parseArray(const string &input) {
    deque<int> result;
    string trimmed = input.substr(1, input.size() - 2);
    stringstream ss(trimmed);
    string item;

    while (getline(ss, item, ',')) {
        if (!item.empty()) {
            result.push_back(stoi(item));
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string p; // 수행할 함수 p
        cin >> p;
        int n; // 배열 수의 개수 n
        cin >> n;
        cin.ignore();
        string input;
        getline(std::cin, input);
        deque<int> dq = parseArray(input);
        int SIZE = p.length();
        bool direction_flag = true;
        bool stop = false;
        for (int i = 0; i < SIZE && !stop; ++i) {
            if (p[i] == 'D') { // 버리기
                if (dq.empty()) {
                    cout << "error\n";
                    stop = true;
                    break;
                } else {
                    if (direction_flag)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            } else if (p[i] == 'R') { // 뒤집기
                direction_flag = !direction_flag;
            }
        }

        if (!stop) {
            if (dq.empty()) {
                cout << "[]\n";
            } else {
                string sb = "[";
                while (!dq.empty()) {
                    if (direction_flag) {
                        sb += to_string(dq.front()) + ",";
                        dq.pop_front();
                        // cout << dq.front() << " ";
                        // dq.pop_front();
                    } else {
                        sb += to_string(dq.back()) + ",";
                        dq.pop_back();
                        // cout << dq.back() << " ";
                        // dq.pop_back();
                    }
                }
                sb.pop_back();
                cout << sb + "]\n";
            }
        }
    }
    return 0;
}