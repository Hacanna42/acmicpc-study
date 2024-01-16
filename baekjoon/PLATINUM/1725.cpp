// 백준: 히스토그램
// https://www.acmicpc.net/problem/1725
// 2024-01-16
// 6549와 동일한 문제. (same problem issue로 레이팅 안들어가서 재제출)

/* 처음엔 복잡한 분할정복 구현이라고 생각했다.
가장 짧은 막대 L에 대해 max(answer, L*SIZE)을 하고
자료구조를 L을 기준으로 나눈 뒤, 각각의 구조에 대해 위 과정을
반복하면 해결할 수 있을 것이라고 생각했다. O(log n)

위의 접근도 유효하지만, Stack을 이용해서 O(n)에 구현하는 방법이 있었다.
1. Stack에 막대 인덱스를 차레대로 삽입
2. if 막대의 높이 < stack.top()의 높이 then .top()의 면적을 계산하고 .pop()
3. 모든 막대의 처리가 끝나면, 남아있는 각 막대에 대해서도 면적 계산
4. 가장 큰 면적이 답이 된다.

이런 천재적인 발상은 누가 처음 시작했을까?

PS. 각 막대에 대해서 확장이 얼마나 가능한지 알아내는것은,
해당 막대의 높이 × (현재 막대의 인덱스 - 스택에서 다음 막대의 인덱스 - 1) 로
간단하게 가능하다.
왜냐하면, 인덱스가 밀렸다는 것은 더 높은 수가 들어왔다는 것이니까.
*/

#include <algorithm>
#include <iostream>
#include <stack>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;

    std::vector<long long> heights(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> heights[i];
    }

    std::stack<long long> stack;
    long long answer = 0;

    for (int i = 0; i < N; ++i) {
        while (!stack.empty() && heights[stack.top()] > heights[i]) {
            long long height = heights[stack.top()];
            stack.pop();
            // 최대 값으로 설정
            long long width = i;
            if (!stack.empty()) {
                width = i - stack.top() - 1;
            }
            answer = std::max(answer, height * width);
        }
        stack.push(i);
    }

    // 남아있는 막대 계산
    while (!stack.empty()) {
        long long height = heights[stack.top()];
        stack.pop();
        long long width = N;
        if (!stack.empty()) {
            width = N - stack.top() - 1;
        }
        answer = std::max(answer, height * width);
    }

    std::cout << answer;
    return 0;
}