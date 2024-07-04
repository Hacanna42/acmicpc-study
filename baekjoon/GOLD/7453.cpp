// 백준: 합이 0인 네 정수
// https://www.acmicpc.net/problem/7453
// 2024-07-04

/* 중간에서 만나기 (MITM, Meet In The Middle) 4개의 배열 문제를 반절로 쪼개서, O(n^4)의 시간 복잡도를 O(n^2) 두개 문제로 만들기.
즉,
1. 배열 A, B, C, D에서 (A, B)쌍과 (C, D)쌍의 합을 배열에 저장하기.
2. 배열을 정렬하고 한 쌍은 첫번째 인덱스부터, 나머지 한쌍은 마지막 인덱스부터 시작해서 투 포인터 탐색.
주의* 동일한 합을 가지는 여러 쌍이 있을 수 있으므로, 바로 포인터를 움직이면 안되고 인접한 인덱스에 동일한 합이 있는지 확인해야 한다.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 배열의 크기 N
    cin >> N;
    int A[N], B[N], C[N], D[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // 중간에서 만나기 (MITM, Meet In The Middle): 일단 (A, B)따로, (C, D)따로 계산
    vector<int> AB, CD;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    // 투 포인터 알고리즘을 위해 (A, B)쌍과 (C, D)쌍을 오름차순 정렬
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    int i = 0;
    int j = CD.size() - 1;
    int AB_size = AB.size();

    ll answer = 0; // 쌍의 개수 (모든 배열의 길이가 4000이고 요소가 모두 0이라면 int 범위를 초과할 수 있다.)

    while (i < AB_size && j >= 0) { // 둘 다 경계 안쪽이어야 함.
        int sum = AB[i] + CD[j];
        /* 쌍의 합이 0일때는 어떤 인덱스를 조절할지 두가지의 선택지가 있다.
        따라서 경계 체크를 해야 함.*/

        if (sum == 0) { // 합이 0인 쌍 발견
            // 주의 : 동일한 합을 가지는 여러 쌍이 있을 수 있으므로, 바로 포인터를 움직이면 안되고 인접한 인덱스에 동일한 합이 있는지 확인해야 한다.
            ll AB_count = 1; // 합이 0인 쌍이 이미 하나 있으므로 1로 초기화
            ll CD_count = 1;
            // (A, B)쌍에 대해서 동일한 합이 있는지 체크
            while (i + 1 < AB_size && AB[i] == AB[i + 1]) {
                ++AB_count; // 동일한 합 +1
                ++i;
            }
            // (C, D)쌍에 대해서 동일한 합이 있는지 체크
            while (j - 1 >= 0 && CD[j] == CD[j - 1]) {
                ++CD_count; // 동일한 합 +1
                --j;
            }

            answer += AB_count * CD_count; // 쌍 조합만큼 정답에 추가
            ++i;                           // 현재 인덱스까지 모두 처리 했으므로 넘기기
            --j;
        }

        else if (sum > 0) {   // 합이 0보다 크다면
            --j;              // j 인덱스를 -1
        } else if (sum < 0) { // 합이 0보다 작다면
            ++i;              // i 인덱스를 +1
        }
    }

    cout << answer;
    return 0;
}