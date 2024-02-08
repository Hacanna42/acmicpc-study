#include <queue>
#include <utility>
#include <vector>

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    auto it = truck_weights.begin();
    int current_bridge_weight = 0;
    queue<pair<int, int>> q; // 시간, 무게
    int time = 0;
    while (it != truck_weights.end() || !q.empty()) {
        ++time;
        if (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int current_truck_weight = q.front().second;
                int current_truck_time = q.front().first;
                q.pop();
                if (--current_truck_time > 0) {
                    q.push({current_truck_time, current_truck_weight});
                } else {
                    current_bridge_weight -= current_truck_weight;
                }
            }
        }

        if (it != truck_weights.end() && current_bridge_weight + *it <= weight) {
            current_bridge_weight += *it;
            q.push({bridge_length, *it});
            ++it;
        }
    }

    return time;
}