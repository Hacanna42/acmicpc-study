// 해결 못함..

#include <iostream>
#include <queue>
#include <vector>

int main() {
    int N;
    std::vector<int> isq;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;
    std::vector<std::queue<int> > q_list(N);

    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        isq.push_back(temp);
    }

    int c = 0;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        if (isq[i] == 0) q_list[c].push(temp);
        ++c;
    }

    std::cin >> N;
    int lastUpdatedIndex = 0;  // 마지막 큐 추적

    for (int i = 0; i < N; ++i) {
        int n;
        std::cin >> n;
        int startIndex = lastUpdatedIndex;
        bool updated = false;

        for (int j = startIndex; j < q_list.size(); ++j) {
            if (!q_list[j].empty()) {
                int front = q_list[j].front();
                q_list[j].pop();
                q_list[j].push(n);
                n = front;
                if (!updated) {
                    lastUpdatedIndex = j;
                    updated = true;
                }
            }
        }
        std::cout << n << " ";
    }
    return 0;
}
