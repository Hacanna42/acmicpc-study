#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Point {
    int x;
    int y;
};

int comparePuzzle(vector<Point> &a, vector<Point> &b) {
    if (a.size() != b.size())
        return 0;
    int n = a.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i].x == b[j].x && a[i].y == b[j].y) {
                ++count;
                break;
            }
        }
    }
    return (count == n ? n : 0);
}

// 전치
void transpose(vector<vector<int>> &info) {
    int n = info.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(info[i][j], info[j][i]);
        }
    }
}

// 수평 뒤집기
void horizontalFlip(vector<vector<int>> &info) {
    int n = info.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(info[i][j], info[i][n - 1 - j]);
        }
    }
}

void rotate90Degrees(vector<vector<int>> &info) {
    // 전치 후 수평 뒤집기
    transpose(info);
    horizontalFlip(info);
}

vector<vector<Point>> convertToAbs(vector<vector<Point>> &info) {
    vector<vector<Point>> puzzles_abs;
    for (const auto &puzzle : info) {
        int abs_point_x = INT_MAX;
        int abs_point_y = INT_MAX;

        // 1. 현재 퍼즐의 기준점 값 찾기
        for (const auto &point : puzzle) {
            abs_point_x = min(abs_point_x, point.x);
            abs_point_y = min(abs_point_y, point.y);
        }

        // 2. 기준점 값으로 모든 값을 absolute value로 변경
        vector<Point> abs_point_list;
        for (const auto &point : puzzle) {
            abs_point_list.push_back({point.x - abs_point_x, point.y - abs_point_y});
        }

        puzzles_abs.push_back(abs_point_list);
        abs_point_list.clear();
    }

    return puzzles_abs;
}

vector<vector<Point>> getCoordinateBFS(vector<vector<int>> &info, int selector) { // 셀렉터는 보드와 퍼즐을 구분하기 위한 매개변수

    // BFS로 보드판의 빈칸 정보를 좌표계로 변환
    queue<Point> q;
    vector<Point> point_list;
    vector<vector<Point>> puzzles;
    int info_size = info.size();
    vector<vector<bool>> visited(info_size, vector<bool>(info_size, false));

    for (int y = 0; y < info_size; ++y) {
        for (int x = 0; x < info_size; ++x) {
            if (!visited[y][x] && info[y][x] == selector) { // 새로운 조각 발견
                visited[y][x] = true;
                q.push({x, y});
                point_list.push_back({x, y});
                while (!q.empty()) {
                    int cur_x = q.front().x;
                    int cur_y = q.front().y;
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int next_x = cur_x + dx[i];
                        int next_y = cur_y + dy[i];
                        // Valid Check
                        if (next_x >= 0 && next_y >= 0 && next_x < info_size && next_y < info_size && !visited[next_y][next_x] && info[next_y][next_x] == selector) {
                            visited[next_y][next_x] = true;
                            q.push({next_x, next_y});
                            point_list.push_back({next_x, next_y});
                        }
                    }
                }
                // 조각 끝.
                puzzles.push_back(point_list);
                point_list.clear();
            }
        }
    }
    return puzzles;
}

// 보드를 채우는 함수 (중복 방지)
void fillBoard(vector<vector<int>> &game_board, vector<Point> &coordinates) {
    for (const auto &co : coordinates) {
        game_board[co.y][co.x] = true;
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {

    // 좌표계로 보드, 조각 변환
    vector<vector<Point>> coordinated_table = getCoordinateBFS(table, 1);
    vector<vector<Point>> coordinated_game_board = getCoordinateBFS(game_board, 0);

    // 절대 좌표로 변환
    vector<vector<Point>> puzzles = convertToAbs(coordinated_table);
    vector<vector<Point>> current_game_board = convertToAbs(coordinated_game_board);

    // 해당 퍼즐이 맞춰졌는지 확인
    vector<bool> visited(puzzles.size(), false);

    int puzzles_size = puzzles.size();

    int answer = 0;
    int loop = 3;
    do {
        int boards_size = current_game_board.size();
        for (int i = 0; i < puzzles_size; ++i) {
            if (!visited[i]) { // 아직 해결 안된 퍼즐이여야만 탐색
                for (int j = 0; j < boards_size; ++j) {
                    int cnt = comparePuzzle(puzzles[i], current_game_board[j]);
                    if (cnt) {             // 퍼즐이 조건을 충족하면
                        visited[i] = true; // 퍼즐을 완료로 표시, 보드를 메꾸기 (중복 방지)
                        fillBoard(game_board, coordinated_game_board[j]);
                        answer += cnt;
                        break;
                    }
                }
            }
        }

        // 90도 돌리기
        rotate90Degrees(game_board);
        coordinated_game_board.clear();                           // 기존 벡터의 모든 요소 제거
        coordinated_game_board = getCoordinateBFS(game_board, 0); // 새로운 값
        current_game_board.clear();
        current_game_board = convertToAbs(coordinated_game_board);

    } while (loop--);

    return answer;
}