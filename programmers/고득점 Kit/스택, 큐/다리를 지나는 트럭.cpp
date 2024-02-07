#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> q;  // 무게, 시간
    int time = 0;             // 총 소요시간
    int weight_on_bridge = 0; // 현재 다리의 무게
    auto it = truck_weights.begin();
    while (it != truck_weights.end() || !q.empty()) {
        ++time;
        if (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int remain_time = q.front().second;
                int current_truck_weight = q.front().first;
                q.pop();
                if (--remain_time > 0) {
                    q.push({current_truck_weight, remain_time});
                } else {
                    weight_on_bridge -= current_truck_weight;
                }
            }
        }

        if (it != truck_weights.end() && weight_on_bridge + *it <= weight) {
            weight_on_bridge += *it;
            q.push({*it, bridge_length});
            it++;
        }
    }

    return time;
}
