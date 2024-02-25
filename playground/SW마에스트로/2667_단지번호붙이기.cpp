#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int dc[4] = {1, -1, 0, 0};
int dr[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int r = 0; r < N; ++r) {
        string temp;
        cin >> temp;
        for (int c = 0; c < N; ++c) {
            map[r][c] = temp[c] - '0';
        }
    }

    int complex_num = 0;
    vector<int> house_nums;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (map[r][c] == 1) {
                int count = 0;
                complex_num++;
                queue<pair<int, int>> q; // r, c
                q.push({r, c});

                while (!q.empty()) {
                    int current_r = q.front().first;
                    int current_c = q.front().second;
                    q.pop();

                    if (map[current_r][current_c] == 1) {
                        map[current_r][current_c] = 0; // 집을 없앰 (방문 표시)
                        count++;

                        for (int i = 0; i < 4; ++i) {
                            int next_r = current_r + dr[i];
                            int next_c = current_c + dc[i];

                            // VALID CHECK
                            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < N) {
                                if (map[next_r][next_c] == 1) { // 집이 존재해야만
                                    q.push({next_r, next_c});
                                }
                            }
                        }
                    }
                }
                house_nums.push_back(count);
            }
        }
    }

    sort(house_nums.begin(), house_nums.end());
    cout << complex_num << "\n";
    for (const auto &house : house_nums) {
        cout << house << "\n";
    }

    return 0;
}