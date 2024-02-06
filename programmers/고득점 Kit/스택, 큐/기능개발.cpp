#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    for (int i = 0; i < progresses.size(); ++i) {
        int day_takes = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0)
            day_takes++;
        q.push(day_takes);
    }
    vector<int> answer;
    int count = 1;
    int latest_takes = q.front();
    q.pop();
    while (!q.empty()) {
        int current_day = q.front();
        q.pop();
        if (current_day <= latest_takes)
            count++;
        else {
            answer.push_back(count);
            latest_takes = current_day;
            count = 1;
        }
    }
    answer.push_back(count);
    return answer;
}