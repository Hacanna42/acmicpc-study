#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool isConvertable(string a, string b) {
    int c = 0;
    for (int i = 0; i < a.size() && c < 2; ++i) {
        if (a[i] != b[i])
            ++c;
    }
    return !(c == 2 || c == 0);
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);
    q.push({begin, 0});

    while (!q.empty()) {
        string current_word = q.front().first;
        int current_w = q.front().second;
        q.pop();

        if (current_word == target)
            return current_w;

        for (int i = 0; i < words.size(); ++i) {
            if (!visited[i] && isConvertable(current_word, words[i])) { // 방문하지 않았고, 변환 가능하면
                q.push({words[i], current_w + 1});
                visited[i] = true;
            }
        }
    }

    return 0;
}