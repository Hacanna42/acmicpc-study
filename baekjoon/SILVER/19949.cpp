// 백준: 영재의 시험
// https://www.acmicpc.net/problem/19949
// 2024-02-08

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void generateSequence(vector<int> &sequence);

vector<int> answer;
int counter = 0;

bool check(const vector<int> &v) {
    for (auto i = 0; i < v.size() - 2; ++i) {
        if (v[i] == v[i + 1] && v[i + 1] == v[i + 2])
            return false;
    }
    return true;
}

void generateSequence(vector<int> &sequence) {
    if (sequence.size() == 10) {
        if (check(sequence)) {
            int correct = 0;
            for (int i = 0; i < 10; ++i) {
                if (sequence[i] == answer[i]) {
                    correct++;
                }
            }
            if (correct >= 5)
                counter++;
        }
        return;
    }

    for (int i = 1; i <= 5; ++i) {
        sequence.push_back(i);
        generateSequence(sequence);
        sequence.pop_back();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i < 10; ++i) {
        int temp;
        cin >> temp;
        answer.push_back(temp);
    }

    vector<int> s;
    generateSequence(s);

    cout << counter;

    return 0;
}