// 백준: 알고리즘 수업 - 피보나치 수 1
// https://www.acmicpc.net/problem/24416
// 2024-01-09

#include <iostream>
int f[41] = {
    0,
};
int count = 0;
int sad_count = 0;
int fibonaci(int N) {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= N; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        ++count;
    }
    return f[N];
}
int sad_fibonaci(int N) {
    if (N == 1 || N == 2) {
        return 1;
    } else {
        ++sad_count;
        return (sad_fibonaci(N - 1) + sad_fibonaci(N - 2));
    }
}
int main() {
    int N;
    std::cin >> N;
    fibonaci(N);
    sad_fibonaci(N);
    std::cout << sad_count + 1 << " " << count;
    return 0;
}