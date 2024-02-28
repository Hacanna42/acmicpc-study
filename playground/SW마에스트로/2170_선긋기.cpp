#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());

    int totalLength = 0;
    int scan_start = -1'000'000'000;
    int scan_end = -1'000'000'000;

    for (const auto &line : lines) {
        int start = line.first;
        int end = line.second;
        if (start > scan_end) { // 선분이 겹치지 않음
            totalLength += scan_end - scan_start;
            scan_start = start;
            scan_end = end;
        } else if (end > scan_end) { // 선분 겹침: 초과
            scan_end = end;
        }
    }

    // 마지막 선분 고려
    totalLength += scan_end - scan_start;
    cout << totalLength;
    return 0;
}