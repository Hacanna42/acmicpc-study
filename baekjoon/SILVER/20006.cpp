// 백준: 랭킹전 대기열
// https://www.acmicpc.net/problem/20006
// 2025-11-25

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    deque<pair<int, vector<string>>> room;
    int player_count, room_limit;
    cin >> player_count >> room_limit;

    while (player_count--) {
        int player_lv;
        string player_name;
        cin >> player_lv >> player_name;

        // 방 탐색
        bool found_room = false;
        for (auto &r : room) {
            int &room_base_lv = r.first;
            vector<string> &room_players = r.second;

            // 참가 가능 조건
            if (abs(player_lv - room_base_lv) > 10 || room_players.size() >= room_limit) {
                continue;
            }

            room_players.push_back(to_string(player_lv) + " " + player_name);
            found_room = true;
            break;
        }

        if (!found_room) {
            room.emplace_back(player_lv, vector<string>{to_string(player_lv) + " " + player_name});
        }
    }

    // 시뮬레이션 완료
    for (auto &r : room) {
        int &room_base_lv = r.first;
        vector<string> &room_players = r.second;
        sort(room_players.begin(), room_players.end(), [](const string &a, const string &b) {
            size_t a_pos = a.find(' ');
            size_t b_pos = b.find(' ');
            string a_nickname = a.substr(a_pos + 1);
            string b_nickname = b.substr(b_pos + 1);

            return a_nickname < b_nickname;
        });
        (room_players.size() >= room_limit) ? cout << "Started!\n" : cout << "Waiting!\n";
        for (const auto &player : room_players) {
            cout << player << "\n";
        }
    }

    return 0;
}