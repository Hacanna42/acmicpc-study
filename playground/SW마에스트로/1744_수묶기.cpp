#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<ll> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), greater<int>());

    // 큰 수 두개씩 곱셈
    // 단, 0과 곱하면 안됨. 1끼리도 곱하면 안됨 (더한 게 더 큼)
    // 음수와도 곱하면 안됨. 단 0과는 곱셈 해야됨
    // 음수와 음수가 있다면 큰것끼리 곱해야됨

    ll total = 0;
    int holder1 = -1, holder2 = -1;
    vector<bool> visited(N, false);

    // 양수 검증
    for (int i = 0; i < N; ++i) {
        if (visited[i]) // 이미 계산한 값 pass
            continue;
        int cur = nums[i];
        if (cur <= 1) // 고려하지 않을 값 pass
            continue;

        if (holder1 == -1) { // 홀더 1이 비어있으면
            if (cur > 1) {   // 양수 기준 0과 1은 곱하는 게 손해
                holder1 = i; // 곱하는 게 이득이면 홀더에 추가한다고 표시
            }
        } else if (holder2 == -1) { // 홀더 2가 비어있으면
            if (cur > 1) {
                holder2 = i;
            }
        }

        // 홀더 두개가 차면
        if (holder1 != -1 && holder2 != -1) {
            visited[holder1] = true;
            visited[holder2] = true;                // 홀더 인덱스를 계산했다고 표시
            total += nums[holder1] * nums[holder2]; // 계산 값에 홀더 둘 곱한 값 추가
            holder1 = -1, holder2 = -1;             // 초기화
        }
    }

    // 재검증 이전에 홀더 초기화
    holder1 = -1, holder2 = -1;
    int zero = -1;

    // 음수 검증
    for (int i = N - 1; i >= 0; --i) { // 거꾸로 검색 (음수니까)
        if (visited[i])                // 이미 계산한 값 pass
            continue;
        int cur = nums[i];
        if (cur > 0)
            continue;                 // 양수 pass: 음수 둘이 곱할 수 없을때만 0 추가 고려
        if (cur == 0 && zero == -1) { // 0이 검색됐는데, zero 홀더가 비어있으면
            zero = i;
            visited[i] = true; // 0을 이미 사용함으로 표시 (이후에 사용할 것)
            continue;
        }

        if (holder1 == -1) { // 홀더 1이 비어있으면
            holder1 = i;
        } else if (holder2 == -1) {
            holder2 = i;
        }

        // 홀더 두개가 차면
        if (holder1 != -1 && holder2 != -1) {
            visited[holder1] = true;
            visited[holder2] = true;
            total += nums[holder1] * nums[holder2]; // 계산 값에 홀더 둘 곱한 값 추가
            holder1 = -1, holder2 = -1;             // 초기화
        }
    }

    // 여기까지 왔으면 남은 음수는 무조건 하나밖에 없다.
    // 음수에 0을 곱하는 경우

    if (zero != -1) {                      // 남은 수에 0이 존재할때만
        for (int i = N - 1; i >= 0; --i) { // 남은 음수 중 제일 큰 음수 검색
            if (visited[i])
                continue;
            int cur = nums[i];
            if (cur >= 0)
                break; // 양수를 발견했으면 음수 구간을 벗어난것임으로 종료

            // 음수 첫 발견
            visited[i] = true;             // 음수를 사용했다고 표시
            total += nums[i] * nums[zero]; // 무조건 0일것임
            break;
        }
    }

    // 곱해지지 않은 값 최종 합
    for (int i = 0; i < N; ++i) {
        if (visited[i])
            continue; // 계산 됐다면 스킵
        total += nums[i];
    }
    cout << total;

    return 0;
}