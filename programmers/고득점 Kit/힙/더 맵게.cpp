#include <functional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const int next : scoville) {
        pq.push(next);
    }

    int answer = 0;

    while (!pq.empty()) {
        int current_scov = pq.top();
        if (current_scov < K) {
            pq.pop();
            if (pq.empty())
                return -1;
            int next_scov = pq.top();
            pq.pop();
            pq.push(current_scov + (next_scov * 2));
            ++answer;
        } else {
            break;
        }
    }
    return answer;
}