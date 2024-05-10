// 백준: 테트로미노
// https://www.acmicpc.net/problem/14500
// 2024-05-09

/*
그냥 단순 구현 브루트포스?
모든 퍼즐에 대해 회전/대칭 절대좌표 구하기
1. 회전, 대칭후 절대좌표로 변환
2. 브루트포스
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Piece {
    int x;
    int y;
};

vector<Piece> transpose(const vector<Piece> &pieces) { // 전치
    vector<Piece> transposed;
    for (const auto &piece : pieces) {
        transposed.push_back({piece.y, piece.x});
    }
    return transposed;
}

vector<Piece> flipHorizontal(const vector<Piece> &pieces, int M) { // 수평 뒤집기
    vector<Piece> flipped;
    for (const auto &piece : pieces) {
        flipped.push_back({piece.x, M - 1 - piece.y});
    }
    return flipped;
}

vector<Piece> flipVertical(const vector<Piece> &pieces, int M) { // 수직 뒤집기
    vector<Piece> flipped;
    for (const auto &piece : pieces) {
        flipped.push_back({M - 1 - piece.x, piece.y});
    }
    return flipped;
}

vector<Piece> absolute(const vector<Piece> &pieces) {
    // 각 x y 좌표의 최소값 빼기: (0, 0) 기준 맞추기
    vector<Piece> absoluted;
    int minX = (~0U >> 2);
    int minY = (~0U >> 2);
    for (const auto &piece : pieces) {
        minX = min(minX, piece.x);
        minY = min(minY, piece.y);
    }

    for (const auto &piece : pieces) {
        absoluted.push_back({piece.x - minX, piece.y - minY});
    }

    return absoluted;
}

vector<Piece> rotate90Degrees(const vector<Piece> &pieces, int M) {
    // 전치 -> 수평 뒤집기 -> 절댓값 변환
    vector<Piece> transposed = transpose(pieces);
    vector<Piece> flipped = flipHorizontal(transposed, M);
    vector<Piece> absoluted = absolute(flipped);

    return absoluted;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 맵 입력받기
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> map[r][c];
        }
    }

    // 테트로미노 기본 정보 (5 종류)
    vector<Piece> puzzle_straight = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
    vector<Piece> puzzle_square = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<Piece> puzzle_ㄱ = {{0, 0}, {0, 1}, {0, 2}, {1, 0}};
    vector<Piece> puzzle_ㄹ = {{0, 2}, {0, 1}, {1, 1}, {1, 0}};
    vector<Piece> puzzle_ㅜ = {{0, 1}, {1, 1}, {1, 0}, {2, 1}};

    // 모든 조합의 퍼즐 정보
    vector<vector<Piece>> puzzles;

    // 퍼즐 집합 저장
    puzzles.push_back(puzzle_straight); // 1. 직선 (회전 1회만)
    puzzles.push_back(rotate90Degrees(puzzle_straight, 4));
    puzzles.push_back(puzzle_square); // 2. 네모 (회전, 대칭 동일)

    puzzles.push_back(puzzle_ㄱ); // 3. 기역자 (회전, 대칭 모두)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            puzzle_ㄱ = rotate90Degrees(puzzle_ㄱ, 4);
            puzzles.push_back(puzzle_ㄱ);
        }
        if (i == 0) {
            puzzle_ㄱ = flipHorizontal(rotate90Degrees(puzzle_ㄱ, 4), 4); // 제자리로 회전 후, 대칭
            puzzles.push_back(puzzle_ㄱ);
        } else if (i == 2) {
            puzzle_ㄱ = flipHorizontal(rotate90Degrees(puzzle_ㄱ, 4), 4); // 제자리로 복귀
            puzzle_ㄱ = flipVertical(puzzle_ㄱ, 4);                       // 대칭
            puzzles.push_back(puzzle_ㄱ);
        }
    }

    puzzles.push_back(puzzle_ㄹ); // 4. 리을자 (회전, 대칭 모두)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            puzzle_ㄹ = rotate90Degrees(puzzle_ㄹ, 4);
            puzzles.push_back(puzzle_ㄹ);
        }
        if (i == 0) {
            puzzle_ㄹ = flipHorizontal(rotate90Degrees(puzzle_ㄹ, 4), 4); // 제자리로 회전 후, 대칭
            puzzles.push_back(puzzle_ㄹ);
        } else if (i == 2) {
            puzzle_ㄹ = flipHorizontal(rotate90Degrees(puzzle_ㄹ, 4), 4); // 제자리로 복귀
            puzzle_ㄹ = flipVertical(puzzle_ㄹ, 4);                       // 대칭
            puzzles.push_back(puzzle_ㄹ);
        }
    }

    puzzles.push_back(puzzle_ㅜ); // ㅜ자 (회전만)
    for (int i = 0; i < 3; ++i) {
        puzzle_ㅜ = rotate90Degrees(puzzle_ㅜ, 4);
        puzzles.push_back(puzzle_ㅜ);
    }

    /*
    1. 인덱스를 잡고 piece와 대치. 안에 있는 점수를 얻고 범위 밖이면 종료
    */

    int max_score = 0;

    for (int cur_y = 0; cur_y < N; ++cur_y) {
        for (int cur_x = 0; cur_x < M; ++cur_x) {
            // 현재 인덱스 = {x, y}
            for (const auto &puzzle : puzzles) { // 검사할 모양
                int cur_score = 0;
                for (const auto &piece : puzzle) {
                    if (cur_x + piece.x < M && cur_y + piece.y < N) { // VALID CHECK
                        cur_score += map[cur_y + piece.y][cur_x + piece.x];
                    } else {
                        cur_score = 0;
                        break; // 경계 밖이라면 다음 퍼즐로 넘기기
                    }
                }
                // 단일 퍼즐 검사 완료
                max_score = max(max_score, cur_score);
            }
        }
    }

    cout << max_score;

    return 0;
}