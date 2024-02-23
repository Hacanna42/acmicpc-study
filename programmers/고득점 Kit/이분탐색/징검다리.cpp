#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int start = 1;
    int end = distance;
    sort(rocks.begin(), rocks.end());
    int answer = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int lastRock = 0; // 출발 지점
        int removeCount = 0;

        // 바위 체크
        for (int i = 0; i < rocks.size(); ++i) {
            if (rocks[i] - lastRock < mid) {
                removeCount++;
            } else {
                lastRock = rocks[i];
            }
        }

        // 도착지점 계산
        if (distance - lastRock < mid)
            removeCount++;

        if (removeCount > n) {
            end = mid - 1;
        } else if (removeCount <= n) {
            answer = mid;
            start = mid + 1;
        }
    }
    return answer;
}