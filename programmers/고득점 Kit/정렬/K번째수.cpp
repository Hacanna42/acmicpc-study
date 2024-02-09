#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (const auto next : commands) {
        int i = next[0], j = next[1], k = next[2];
        vector<int> temp(array.begin() + i - 1, array.begin() + j);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }
    return answer;
}