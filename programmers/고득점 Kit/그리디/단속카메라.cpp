#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int last_camera_pos = -30001;
    sort(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    for (int i = 0; i < routes.size(); ++i) {
        int start = routes[i][0];
        int end = routes[i][1];
        if (last_camera_pos >= start && last_camera_pos <= end)
            continue;
        else {
            ++answer;
            last_camera_pos = end;
        }
    }
    return answer;
}