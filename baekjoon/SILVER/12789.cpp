// 백준: 도키도키 간식드리미
// https://www.acmicpc.net/problem/12789
// 2024-01-04

#include <iostream>
#include <stack>
#include <vector>

int main() {
    int N;
    std::vector<int> list;
    std::cin >> N;
    // 정보 입력받기
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }

    // 알고리즘 시작
    int count = 1;
    int index = 0;
    int prenum = 1001;
    std::stack<int> stack;
    bool isGood = true;
    while (true) {
        // count번을 찾는다
        for (int i = index; (i < list.size()) && isGood; ++i) {
            if (list[i] == count) {
                for (int j = index; j < i; ++j) {
                    // stack에 들어간 사람이 내림차순인지 확인
                    if (!(list[j] < prenum)) {
                        // 만약 먼저 들어간 사람보다 뒷 사람이 들어가면
                        isGood = false;
                        break;
                    }
                    prenum = list[j];
                    stack.push(list[j]);
                }
                index = i + 1;
                ++count;
                break;
            }
        }

        if (!stack.empty() && stack.top() == count) {
            stack.pop();
            prenum = (stack.empty() ? 1001 : stack.top());
            ++count;
        }

        if (index >= list.size() || !isGood) break;
    }

    std::cout << (isGood ? "Nice" : "Sad");
    return 0;
}