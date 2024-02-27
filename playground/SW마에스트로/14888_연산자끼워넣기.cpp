#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> operators(4);
int N;

int min_answer = (~0U >> 2);
int max_answer = (~0U >> 1) * -1;

void dfs(int depth, int current, vector<int> &operators) {
    if (depth == N) {
        min_answer = min(min_answer, current);
        max_answer = max(max_answer, current);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) { // 연산자가 사용 가능하다면
            operators[i] -= 1;

            if (i == 0) // 덧셈
                dfs(depth + 1, current + nums[depth], operators);
            else if (i == 1) // 뺄셈
                dfs(depth + 1, current - nums[depth], operators);
            else if (i == 2) // 곱셈
                dfs(depth + 1, current * nums[depth], operators);
            else if (i == 3) // 나눗셈
                dfs(depth + 1, current / nums[depth], operators);

            operators[i] += 1;
        }
    }
}

int main() {
    cin >> N;
    nums.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }

    dfs(1, nums[0], operators);

    cout << max_answer << "\n" << min_answer;
    return 0;
}