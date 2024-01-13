// 백준: 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660
// 2024-01-13

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int table_size, testcases;
    std::cin >> table_size >> testcases;
    std::vector<std::vector<long long> > table_prefix(
        table_size + 1, std::vector<long long>(table_size + 1, 0));
    long long sum = 0;
    for (int i = 1; i <= table_size; ++i) {
        for (int j = 1; j <= table_size; ++j) {
            int input_number;
            std::cin >> input_number;
            sum += input_number;
            table_prefix[j][i] = sum;
        }
    }

    for (int cases = 0; cases < testcases; ++cases) {
        int x, y, to_x, to_y;
        std::cin >> y >> x >> to_y >> to_x;
        long long answer = 0;
        // Y 좌표 반복
        for (int iy = y; iy <= to_y; ++iy) {
            // X 좌표 반복
            if (x != 1)
                answer += table_prefix[to_x][iy] - table_prefix[x - 1][iy];
            else if (x == 1 && iy != 1)
                answer +=
                    table_prefix[to_x][iy] - table_prefix[table_size][iy - 1];
            else
                answer += table_prefix[to_x][iy] - table_prefix[x - 1][iy];
        }
        std::cout << answer << "\n";
    }
    return 0;
}