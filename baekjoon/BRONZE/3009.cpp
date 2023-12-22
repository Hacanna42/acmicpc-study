// 백준: 네 번째 점
// https://www.acmicpc.net/problem/3009
// 2023-12-22

/*
XOR연산을 사용하면 쉽게 배열에서 unique한 수를 찾을 수 있다.
XOR연산에서 동일한 수를 비교하면 결국에 모두 상쇄되어 0이 남는데, 0과 나머지
정수를 비교하면 결국 그 값 자체가 되기 때문이다.
*/
#include <iostream>
#include <vector>
int main() {
    std::vector<int> array_x;
    std::vector<int> array_y;
    for (int i = 0; i < 3; i++) {
        int x, y;
        std::cin >> x >> y;
        array_x.push_back(x);
        array_y.push_back(y);
    }
    int unique_x = array_x[0] ^ array_x[1] ^ array_x[2];
    int unique_y = array_y[0] ^ array_y[1] ^ array_y[2];
    std::cout << unique_x << " " << unique_y;
    return 0;
}