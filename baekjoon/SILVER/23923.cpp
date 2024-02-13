// 백준: 아주 서바이벌
// https://www.acmicpc.net/problem/23293
// 2024-02-13

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

struct state {
    int pid;
    int pos = 1;
    vector<int> inv;
};

unordered_map<int, state> player;
vector<int> cheated_log;
set<int> blocked_pid;

bool del_item(vector<int> &inv, int item_id) {
    auto it = find(inv.begin(), inv.end(), item_id);
    bool found = (it != inv.end());
    if (found) {
        inv.erase(it);
    }
    return found;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, N;
    cin >> T >> N;
    // 플레이어 상태 map
    for (int i = 0; i < T; ++i) {
        int uid, pid, arg;
        char action;
        cin >> uid >> pid >> action >> arg;
        if (action == 'M') { // 이동
            player[pid].pos = arg;
        }
        if (action == 'F') { // 획득
            player[pid].inv.push_back(arg);
            if (player[pid].pos != arg) {
                cheated_log.push_back(uid);
            }
        }
        if (action == 'C') { // 조합
            int comb_item;
            cin >> comb_item;
            bool temp_a = del_item(player[pid].inv, arg);
            bool temp_b = del_item(player[pid].inv, comb_item);
            if (!(temp_a && temp_b)) {
                cheated_log.push_back(uid);
            }
        }
        if (action == 'A') { // 공격
            if (player[pid].pos != player[arg].pos) {
                cheated_log.push_back(uid);
                blocked_pid.insert(pid);
            }
        }
    }

    // 출력
    cout << cheated_log.size() << "\n";
    for (int i = 0; i < cheated_log.size(); ++i) {
        cout << cheated_log[i] << " ";
    }
    if (!cheated_log.empty())
        cout << "\n";
    cout << blocked_pid.size() << "\n";
    for (const int &pid : blocked_pid) {
        cout << pid << " ";
    }
    return 0;
}