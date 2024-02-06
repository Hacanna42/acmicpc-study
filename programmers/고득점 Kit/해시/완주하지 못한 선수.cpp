#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for (const string next : participant) {
        m[next]++;
    }
    for (const string next : completion) {
        m[next]--;
        if (m[next] == 0)
            m.erase(next);
    }
    string answer = "";
    for (const auto iter : m) {
        answer = iter.first;
    }
    return answer;
}