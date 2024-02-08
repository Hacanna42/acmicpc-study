#include <queue>
#include <utility>
#include <vector>

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    auto it = truck_weights.begin();
    int current_bridge_weight = 0;
    queue<pair<int, int>> q; // 무게, 시간
    int time = 0;

    while (it != truck_weights.end() || !q.empty()) {
        ++time;
        if (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int current_time = q.front().second;
                int current_weight = q.front().first;
                q.pop();
                if (--current_time > 0)
                    q.push({current_weight, current_time});
                else {
                    current_bridge_weight -= current_weight;
                }
            }
        }

        // 트럭 ㄱ?
        if (it != truck_weights.end()) {
            if (current_bridge_weight + *it <= weight) {
                current_bridge_weight += *it;
                q.push({*it, bridge_length});
                ++it;
            }
        }
    }
    return time;
}