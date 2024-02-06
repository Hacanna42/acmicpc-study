#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> set;
    for (const auto next : nums) {
        set.insert(next);
    }
    int answer = min(nums.size() / 2, set.size());
    return answer;
}