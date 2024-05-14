// 백준: 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662
// 2024-05-14

#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/*
1. 최소 힙과 최대 힙을 동시에 운영해야 한다.
2. 최대 힙이나 최소 힙에서 .pop 된건 서로 알 수 없다.
3. 따라서, 숫자의 출현 횟수를 기록해놓고 valid 한지 체크한다.
*/

class DoubleEndedPriorityQueue {
  private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> count; // 출현 횟수

    template <typename T> void clean(T &heap) { // 값 동기화
        while (!heap.empty() && count[heap.top()] == 0) {
            heap.pop();
        }
    }

  public:
    void insert(int value) {
        maxHeap.push(value);
        minHeap.push(value);
        count[value]++;
    }

    void deleteMax() {
        clean(maxHeap);
        if (!maxHeap.empty()) { // 문제 본문: 비어있다면 무시해도 좋다.
            int value = maxHeap.top();
            maxHeap.pop();
            count[value]--;
        }
    }

    void deleteMin() {
        clean(minHeap);
        if (!minHeap.empty()) {
            int value = minHeap.top();
            minHeap.pop();
            count[value]--;
        }
    }

    int getMax() {
        clean(maxHeap);
        // if (!maxHeap.empty())
        return maxHeap.top();
    }

    int getMin() {
        clean(minHeap);
        // if (!minHeap.empty())
        return minHeap.top();
    }

    bool empty() {
        clean(minHeap);
        return minHeap.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;

    while (TC--) {
        DoubleEndedPriorityQueue depq;
        int k;
        cin >> k;
        while (k--) {
            char command;
            int n;
            cin >> command >> n;
            if (command == 'I') { // INSERT
                depq.insert(n);
            } else if (command == 'D') { // DELETE
                if (n == 1)              // 최댓값
                    depq.deleteMax();
                else if (n == -1) // 최솟값
                    depq.deleteMin();
            }
        }

        // 출력
        if (depq.empty())
            cout << "EMPTY\n";
        else {
            cout << depq.getMax() << " " << depq.getMin() << "\n";
        }
    }

    return 0;
}