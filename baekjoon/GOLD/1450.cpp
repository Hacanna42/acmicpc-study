// 백준: 냅색문제
// https://www.acmicpc.net/problem/1450
// 2024-01-29

/* MITM과 부분집합, 이분탐색 등을 사용해서 푸는 문제 */

#include <algorithm>
#include <iostream>
#include <vector>

// 분할
std::vector<long long> group1, group2;

void findSubsets(long long L, long long sum,
                 const std::vector<long long>& items,
                 std::vector<long long>& subsets) {
    if (L == items.size()) {
        subsets.push_back(sum);
        return;
    }

    findSubsets(L + 1, sum, items, subsets);
    findSubsets(L + 1, sum + items[L], items, subsets);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, C;
    std::cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        int w;
        std::cin >> w;
        if (i < N / 2)
            group1.push_back(w);
        else
            group2.push_back(w);
    }

    std::vector<long long> subsets1, subsets2;
    findSubsets(0, 0, group1, subsets1);
    findSubsets(0, 0, group2, subsets2);

    std::sort(subsets1.begin(), subsets1.end());
    std::sort(subsets2.begin(), subsets2.end());

    long long count = 0;
    for (long long w : subsets1) {
        long long remain_weight = C - w;

        // for (int w2 : subsets2) {
        //     if (w2 <= remain_weight) count++;
        // }

        long long l = 0;
        long long r = subsets2.size();
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (subsets2[mid] <= remain_weight) {
                l = mid + 1;
            } else
                r = mid;
        }

        // auto iter =
        //     std::upper_bound(subsets2.begin(), subsets2.end(),
        //     remain_weight);
        count += l;
    }
    std::cout << count;
    return 0;
}