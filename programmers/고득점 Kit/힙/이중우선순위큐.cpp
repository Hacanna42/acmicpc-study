#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (string op : operations) {
        char command = op[0];
        int num = stoi(op.substr(2));

        if (command == 'I') {
            ms.insert(num);
        } else if (!ms.empty()) {
            if (num == 1) {
                // 최댓값 삭제
                auto it = prev(ms.end());
                ms.erase(it);
            } else if (num == -1) {
                // 최솟값 삭제
                ms.erase(ms.begin());
            }
        }
    }

    if (ms.empty()) {
        return {0, 0};
    } else {
        return {*ms.rbegin(), *ms.begin()};
    }
}