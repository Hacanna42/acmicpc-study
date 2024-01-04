// 백준: 풍선 터뜨리기
// https://www.acmicpc.net/problem/2346
// 2024-01-04

/*
모듈러 계산으로 새로운 index를 계산한 게 실수였다.
풍선의 정보를 담은 vector을 확인해가며 직접 브루트포스로 세는게 유효했다.
*/

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

// 숫자가 주어지면, 이동 후 index 번호 반환하는 함수
int get_index_after_move(int index, int move, int dequesize,
                         std::vector<bool>& isPopped) {
    if (move > 0) {
        while (move > 0) {
            index = (index + 1) % dequesize;
            if (!isPopped[index]) --move;
        }
    } else {
        while (move < 0) {
            index = (index - 1 + dequesize) % dequesize;
            if (!isPopped[index]) ++move;
        }
    }
    return index;
}

int main() {
    int N;
    std::deque<std::pair<int, int> > deque;
    std::cin >> N;
    std::vector<bool> isPopped(N, false);
    for (int i = 1; i <= N; ++i) {
        int temp;
        std::cin >> temp;
        deque.push_back(std::make_pair(i, temp));
    }
    int index = 0;
    int remain = N;
    while (remain > 0) {
        int ballon = deque[index].first;
        int move = deque[index].second;
        std::cout << ballon << " ";
        // deque.erase(deque.begin() + index);
        isPopped[index] = true;
        --remain;
        if (remain > 0)
            index = get_index_after_move(
                index, move, static_cast<int>(deque.size()), isPopped);
    }
    return 0;
}