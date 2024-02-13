#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int move = n - 1; // 최대로 오른쪽으로만 이동하는 경우

    for (int i = 0; i < n; i++) {
        // 상하 이동 최소 횟수 계산
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        // 좌우 이동 최소 횟수 계산
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++;
        }
        move = min(move, i + n - next + min(i, n - next));
    }

    return answer + move;
}
