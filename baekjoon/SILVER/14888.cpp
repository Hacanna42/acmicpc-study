// 백준: 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888
// 2024-01-09

#include <iostream>
#include <vector>

int N;
std::vector<int> numbers;
char op[4] = {'+', '-', 'x', '%'};
// 각 오퍼레이터 체크 리스트
int operator_check[4] = {
    0,
};
int max = -1000000000;
int min = 1000000000;

int calculate(long long current_sum, char op, long long next_number) {
    if (op == '+')
        return current_sum + next_number;
    else if (op == '-')
        return current_sum - next_number;
    else if (op == 'x')
        return current_sum * next_number;
    else
        return current_sum / next_number;
}

void dfs(int L, long long current_sum) {
    if (L == N - 1) {
        if (current_sum > max) max = current_sum;
        if (current_sum < min) min = current_sum;
        return;
    }
    for (int j = 0; j < 4; ++j) {
        if (operator_check[j]) {
            --operator_check[j];
            long long new_sum = calculate(current_sum, op[j], numbers[L + 1]);
            dfs(L + 1, new_sum);
            ++operator_check[j];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
    for (int i = 0; i < 4; ++i) {
        int count;
        std::cin >> count;
        operator_check[i] = count;
    }
    dfs(0, numbers[0]);
    std::cout << max << "\n" << min;
    return 0;
}