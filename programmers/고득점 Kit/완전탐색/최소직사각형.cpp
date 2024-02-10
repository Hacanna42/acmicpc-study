#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    // 항상 가로는 길게, 세로는 짧게 정렬
    int ans_width = 0;
    int ans_height = 0;
    for (const auto next : sizes) {
        int width = next[0];
        int height = next[1];
        int adjust_width = max(width, height);
        int adjust_height = min(width, height);

        ans_width = max(ans_width, adjust_width);
        ans_height = max(ans_height, adjust_height);
    }

    return ans_width * ans_height;
}