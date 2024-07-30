#include <iostream>
#include <vector>
#define MOD 1'000'000'007
using namespace std;

struct Matrix {
    int rows;
    int cols;
    vector<vector<int>> vec;
};

vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();    // A 행의 수
    int m = A[0].size(); // A 열의 수이자 B의 행의 수
    int p = B[0].size(); // B 열의 수

    vector<vector<int>> result(n, vector<int>(p, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                result[i][j] = (result[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return result;
}

int main() {
    vector<Matrix> matrices;
    int N; // 행렬의 총 개수 N
    cin >> N;
    for (int i = 0; i < N; ++i) { // 행렬 입력
        Matrix matrix;
        cin >> matrix.rows >> matrix.cols; // 행의 개수 rows, 열의 개수 cols
        vector<vector<int>> vec(matrix.rows, vector<int>(matrix.cols));
        for (int y = 0; y < matrix.rows; ++y) {
            for (int x = 0; x < matrix.cols; ++x) {
                cin >> vec[y][x];
            }
        }
        matrix.vec = vec;
        matrices.push_back(matrix);
    }

    // 행렬을 입력 순서대로 탐색하면서 계산 가능한지 여부 파악
    int SIZE = matrices.size();
    Matrix cur_matrix = matrices[0]; // 첫번째 입력 행렬부터 계산
    for (int i = 1; i < SIZE; ++i) {
        if (cur_matrix.cols == matrices[i].rows) { // 현재까지 계산한 행렬과 입력된 행렬이 계산 가능한지 확인
            vector<vector<int>> result = multiplyMatrices(cur_matrix.vec, matrices[i].vec);
            cur_matrix.rows = result.size();
            cur_matrix.cols = result[0].size();
            cur_matrix.vec = result;
        } else { // 계산이 불가능하다면
            cout << "-1";
            return 0;
        }
    }

    int answer = 0;

    for (int y = 0; y < cur_matrix.rows; ++y) {
        for (int x = 0; x < cur_matrix.cols; ++x) {
            answer = (answer + cur_matrix.vec[y][x]) % MOD;
        }
    }

    cout << answer;
    return 0;
}
