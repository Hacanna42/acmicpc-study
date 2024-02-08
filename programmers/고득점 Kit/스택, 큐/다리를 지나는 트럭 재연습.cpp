#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // truck_weights는 다리를 지나야 하는 트럭들의 무게
    // weight 는 다리가 수용 가능한 총 무게
    // bridge_length는 다리의 길이

    queue<pair<int, int>> q; // 무게, 시간
    auto it = truck_weights.begin();
    int time = 0;
    int current_bridge_weight = 0;
    while (it != truck_weights.end() || !q.empty()) {
        ++time;
        if (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int current_truck_weight = q.front().first;
                int current_time = q.front().second;
                q.pop();
                if (--current_time > 0) {
                    q.push({current_truck_weight, current_time});
                } else {
                    current_bridge_weight -= current_truck_weight;
                }
            }
        }
        // 트럭이 들어갈 수 있으면 ㄱ
        if (it != truck_weights.end() && *it + current_bridge_weight <= weight) {
            current_bridge_weight += *it;
            q.push({*it, bridge_length});
            ++it;
        }
    }

    return time;
}
