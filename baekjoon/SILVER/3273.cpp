// 백준: 두 수의 합
// https://www.acmicpc.net/problem/3273
// 2024-01-29

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, x;
    std::cin >> n;
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::cin >> x;

    std::sort(v.begin(), v.end());

    int count = 0;
    int start = 0, end = n - 1;
    while (start < end) {
        int sum = v[start] + v[end];
        if (sum == x) {
            count++;
            start++;
        } else if (sum < x)
            start++;
        else
            end--;
    }

    std::cout << count;
    return 0;
}