#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    for (const auto next : clothes) {
        map[next[1]]++;
    }
    int answer = 1;
    for (const auto iter : map) {
        answer *= iter.second + 1;
    }

    return answer - 1;
}