#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int> map;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        map.insert({t, 0}); // map에 학생들을 기본값으로 추가
    }

    cin.ignore(); // cin 이후  버퍼에 남아있는 개행 문자 제거

    for (int i = 0; i < n; ++i) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            map[word]++;
        }
    }

    vector<pair<int, string>> arr;
    for (auto it = map.begin(); it != map.end(); ++it) { // 반복자로 탐색 후 정렬을 위해 vector에 삽입
        arr.push_back({it->second, it->first});
    }

    // 문제 본문: 인기도가 높은 학생부터 낮은 학생 순으로 출력하고, 인기도가 같은 경우 학생 이름 기준으로 오름차순으로 출력한다.

    sort(arr.begin(), arr.end(), [](pair<int, string> &a, pair<int, string> &b) { // (anonymous function)
        if (a.first == b.first) {                                                 // 인기도가 같으면
            return a.second < b.second;                                           // 학생 이름 기준 오름차순
        }
        return a.first > b.first; // 이외는 인기도가 높은 학생 순
    });

    for (const auto &next : arr) {
        cout << next.second << " " << next.first << "\n";
    }
    return 0;
}