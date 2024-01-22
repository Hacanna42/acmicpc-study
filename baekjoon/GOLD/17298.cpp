// 백준: 오큰수
// https://www.acmicpc.net/problem/17298
// 2024-01-22

#include <limits.h>

#include <deque>
#include <iostream>
#include <stack>
#include <vector>

/* 스택은 생각보다 쓸 곳이 많구나..
히스토그램도 풀고.... */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> numbers(N), nge(N, -1);
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    std::stack<int> s;
    for (int i = 0; i < N; ++i) {
        while (!s.empty() && numbers[s.top()] < numbers[i]) {
            nge[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < N; ++i) {
        std::cout << nge[i] << " ";
    }

    return 0;
}

// :(
// std::deque<int> deque;

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     int N;
//     std::cin >> N;
//     for (int i = 0; i < N; ++i) {
//         int temp;
//         std::cin >> temp;
//         if (temp < min) min = temp;
//         deque.push_back(temp);
//     }
//     std::deque<int> deque_temp;
//     for (int i = 1; i <= N; ++i) {  // 각 오큰수 N에 대해 반복
//         // NGE(N)을 설정하고, 스택에서 맨 아랫값을 target으로 설정
//         int target_num = deque.front();
//         // 어차피 원소 i의 오른편 원소만 고려하니까, 앞으로 쓸일이 없으므로
//         // .pop()

//         deque.pop_front();

//         // 오큰수 검색
//         bool isNGE = false;
//         while (!deque.empty()) {
//             // 오큰수를 발견했다면
//             if (deque.front() > target_num) {
//                 isNGE = true;
//                 std::cout << deque.front() << " ";
//                 // temp로 옮겼었던 원소 복구
//                 while (!deque_temp.empty()) {
//                     deque.push_front(deque_temp.back());
//                     deque_temp.pop_back();
//                 }
//                 break;
//             } else {
//                 // 오큰수가 아니라면 temp로 잠시 옮김
//                 deque_temp.push_back(deque.front());
//                 deque.pop_front();
//             }
//         }
//         if (!isNGE) {
//             std::cout << "-1"
//                       << " ";
//             // temp로 옮겼었던 원소 복구
//             while (!deque_temp.empty()) {
//                 deque.push_front(deque_temp.back());
//                 deque_temp.pop_back();
//             }
//         }
//     }
// }