#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[8] = {
    false,
};

void calculate(vector<vector<int>> &dungeons, int k, int count) {
    bool completed = true;
    answer = max(answer, count);
    for (int i = 0; i < dungeons.size(); ++i) {
        // 아직 탐험하지 않았고, 탐험 가능하다면
        if (!visited[i] && k >= dungeons[i][0]) {
            completed = false;
            visited[i] = true;
            calculate(dungeons, k - dungeons[i][1], count + 1);
            visited[i] = false;
        }
    }
    if (completed)
        return;
}

int solution(int k, vector<vector<int>> dungeons) {
    calculate(dungeons, k, 0);

    return answer;
}