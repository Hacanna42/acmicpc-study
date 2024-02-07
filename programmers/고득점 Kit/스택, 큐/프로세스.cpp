#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q; // id, priority
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); ++i) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    int answer = 0;
    while (!q.empty()) {
        int current_process = q.front().first;
        int current_priority = q.front().second;
        q.pop();
        if (current_priority == pq.top()) {
            pq.pop();
            answer++;
            if (current_process == location)
                break;
        } else {
            q.push({current_process, current_priority});
        }
    }

    return answer;
}