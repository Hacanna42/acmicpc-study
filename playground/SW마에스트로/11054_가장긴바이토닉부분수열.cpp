#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> lis(N, 1);
    vector<int> lds(N, 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j > i; --j) {
            if (nums[j] < nums[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
    }

    int max_answer = 0;
    for (int i = 0; i < N; ++i) {
        max_answer = max(max_answer, lds[i] + lis[i] - 1);
    }

    cout << max_answer;

    return 0;
}