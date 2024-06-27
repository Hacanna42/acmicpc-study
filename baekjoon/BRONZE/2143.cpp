// 백준: 두 배열의 합
// https://www.acmicpc.net/problem/2143
// 2024-06-27

/* 사고 과정:
각 배열에서 특정 구간의 합으로 만들 수 있는 숫자를 저장하기.
메모리 제한이 64MB이기 때문에 vector을 사용하면 안되고, unordered_map을 사용해야 할 것 같다.
unordered_map에 key를 배열의 구간 합으로 만들 수 있는 값으로, value를 그 값의 출현 빈도로 해야겠다.
1,000,000,000
0부터 T까지 반복을 돌리면서(i) a_map[i]의 값이 있을때 b_map[T-i]의 값도 있다면 두 값을 곱한 값을 정답에 누적할 수 있다.

최적화 포인트:
1. unordered_map으로 빈도 수 저장
2. 부분 배열의 합을 매번 계산하지 않고, 누적합 배열로 계산
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    // 입력
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int a_size, b_size;
    cin >> a_size;
    int a[a_size];
    int prefix = 0; // 누적합
    for (int i = 0; i < a_size; ++i) {
        cin >> a[i];
        a[i] += prefix;
        prefix = a[i];
    }

    cin >> b_size;
    int b[b_size];
    prefix = 0; // 초기화
    for (int i = 0; i < b_size; ++i) {
        cin >> b[i];
        b[i] += prefix;
        prefix = b[i];
    }

    // 효율적으로 빈도 수를 저장하기 위해 map 선언
    unordered_map<int, int> map_b;
    unordered_map<int, int> map_a;

    for (int len = 0; len < a_size; ++len) {
        for (int start = 0; start < a_size - len; ++start) {
            int end = start + len;
            if (start == 0) // edge case
                map_a[a[end]]++;
            else
                map_a[a[end] - a[start - 1]]++;
        }
    }

    for (int len = 0; len < b_size; ++len) {
        for (int start = 0; start < b_size - len; ++start) {
            int end = start + len;
            if (start == 0) // edge case
                map_b[b[end]]++;
            else
                map_b[b[end] - b[start - 1]]++;
        }
    }

    // 해시함수의 오버헤드때문에 생각하는 것보다 10억번 탐색은 훨씬 오래 걸린다.
    // int answer = 0;
    // for (int i = 0; i < 1'000'000'000; ++i) {
    //     answer += map_a[i] * map_b[1'000'000'000 - i];
    // }

    // unordered_map<int, int>::iterator을 이용해서 효율적으로 탐색

    long long answer = 0; // 배열이 모두 0일때 answer가 int 범위를 벗어날 수 있다.
    for (const auto &pair_a : map_a) {
        int key_a = pair_a.first;
        int value_a = pair_a.second;
        int target_b = T - key_a;
        if (map_b.find(target_b) != map_b.end()) {
            answer += static_cast<long long>(value_a) * map_b[target_b];
        }
    }

    cout << answer;

    return 0;
}