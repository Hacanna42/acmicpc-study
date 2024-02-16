#include <algorithm>
#include <functional>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> dfs(vector<bool> &visited, vector<string> &route, vector<vector<string>> &tickets, int index) {
    if (route.size() == tickets.size()) {
        route.push_back(tickets[index][1]);
        return route;
    }

    string current_city = tickets[index][0];
    string next_city = tickets[index][1];

    for (int i = 0; i < tickets.size(); ++i) {
        if (!visited[i] && tickets[i][0] == next_city) { // 다음 경로를 찾음
            visited[i] = true;
            route.push_back(next_city);
            vector<string> result = dfs(visited, route, tickets, i);
            if (!result.empty()) {
                return result;
            }
            visited[i] = false;
            route.pop_back();
        }
    }

    return {};
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<string> route;
    route.push_back("ICN");
    for (int i = 0; i < tickets.size(); ++i) {
        if (tickets[i][0] == "ICN") {
            vector<bool> visited(tickets.size());
            visited[i] = true;
            dfs(visited, route, tickets, i);
        }
    }

    return route;
}