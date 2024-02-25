#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<bool> visited(100001, false);

    queue<pair<int, int>> q;
    q.push({N, 0});
    while (!q.empty()) {
        int cur_pos = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        if (cur_pos == K) {
            cout << cur_time;
            break;
        }

        if (!visited[cur_pos]) {
            visited[cur_pos] = true;
            if (cur_pos - 1 >= 0 && !visited[cur_pos - 1])
                q.push({cur_pos - 1, cur_time + 1});
            if (cur_pos + 1 <= 100000 && !visited[cur_pos + 1])
                q.push({cur_pos + 1, cur_time + 1});
            if (cur_pos * 2 <= 100000 && !visited[cur_pos * 2])
                q.push({cur_pos * 2, cur_time + 1});
        }
    }

    return 0;
}