#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    // 여벌을 잃어버린 사람
    for (auto it = lost.begin(); it != lost.end();) {
        if (find(reserve.begin(), reserve.end(), *it) != reserve.end()) {
            reserve.erase(find(reserve.begin(), reserve.end(), *it));
            it = lost.erase(it);
        } else {
            ++it;
        }
    }

    int answer = n - lost.size();
    for (int l : lost) {
        auto it = find_if(reserve.begin(), reserve.end(), [l](int r) { return abs(l - r) == 1; });
        if (it != reserve.end()) {
            ++answer;
            reserve.erase(it);
        }
    }

    return answer;
}