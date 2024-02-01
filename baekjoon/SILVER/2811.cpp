// 백준: 상범이의 우울
// https://www.acmicpc.net/problem/2811
// 2024-02-01
// 업랜디
// 보류 ㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜ

#include <iostream>
#include <vector>
std::vector<bool> flower;
std::vector<int> feelings;

void checkNextFeeling(int index);

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        feelings.push_back(temp);
    }

    flower.assign(N, false);
    // 뒤에서부터 순회
    int index_of_max_sad = 0;
    int count = 0;
    int start_index = 0;
    int max_count = 0;
    int max_index = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (feelings[i] < 0) {
            if (count == 0) start_index = i;
            count++;
        } else if (feelings[i] >= 0) {
            count = 0;
        }
        if (count > max_count) {
            max_count = count;
            max_index = start_index;
        }

        // 우울하다면
        checkNextFeeling(i);
    }

    // 3배
    int aaa = max_count * 3;
    int i = 1;
    while (aaa > 0) {
        if (start_index - i < 0) break;
        flower[start_index - i] = true;
        i++;
        aaa--;
    }

    for (int i = 0; i < N; ++i) {
        std::cout << flower[i] << " ";
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        if (flower[i]) {
            answer++;
        }
    }

    // std::cout << answer;
    return 0;
}

void checkNextFeeling(int index) {
    if (index >= 0 && feelings[index] < 0) {
        flower[index - 1] = true;
        checkNextFeeling(index - 1);
    }
}