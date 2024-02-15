#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

/*
처음 생각한 접근 방법
1. 테두리를 모두 그린다
2. 주어진 좌표보다 한칸 안쪽으로 모두 색칠한다
3. 색칠된 곳에 테두리가 포함되어있으면 해당 테두리를 제거한다
4. 외부의 테두리만 남는다

인접 테두리 간섭 해결법
1. 현재 테두리에서 이동 가능한 방향을 조사한다
2. 방향이 2개라면, 현재 테두리는 유효한 테두리
3. 방향이 3개라면, 현재 테두리는 인접한 테두리이므로, 서로 반대되는 위치에 있는 테두리 방향으로 가야함.
(위, 아래, 좌측에 테두리가 있다면, 수직 방향이 유효함)

테두리 꼭지점에서의 인접 간섭 해결법?


ps. 그냥 그래프를 2배로 늘리고, 정답을 /2로 나누면 된다. 간단했다.
처음에 이 생각을 했었는데, 두배로 늘리고 최단 거리를 찾는 과정에서 뭔가 엣지 케이스가 발생할 것 같았는데. 아니었다.
*/

// int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
// int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// bool isBorder(int x, int y, bool (&map)[52][52]) {
//     if (!map[y][x]) return false; // 사각형 내부가 아니면 false 반환;
//     for (int i=0;i<8;++i) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         // Valid Check
//         if (nx > 0 && ny > 0 && nx <= 50 && ny <= 50) {
//             if (!map[ny][nx]) { // 주변 4방향 중 빈칸이 있다면 테두리임
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer = INT_MAX;

void find(int cx, int cy, int ix, int iy, int cur, bool (&map)[102][102]) {
    if (cx == ix && cy == iy) {
        answer = min(answer, cur / 2);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (map[nx][ny]) {
            map[nx][ny] = false;
            find(nx, ny, ix, iy, cur + 1, map);
            map[nx][ny] = true;
        }
    }
    return;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    bool map[102][102] = {false};
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    // 맵 채우기
    for (const auto &rec : rectangle) {
        int x1 = rec[0] * 2, y1 = rec[1] * 2;
        int x2 = rec[2] * 2, y2 = rec[3] * 2;

        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                map[i][j] = true;
            }
        }
    }

    // 속 파내기
    for (const auto &rec : rectangle) {
        int x1 = rec[0] * 2 + 1, y1 = rec[1] * 2 + 1;
        int x2 = rec[2] * 2 - 1, y2 = rec[3] * 2 - 1;
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                map[i][j] = false;
            }
        }
    }

    map[characterX][characterY] = false;
    find(characterX, characterY, itemX, itemY, 0, map);
    return answer;
}