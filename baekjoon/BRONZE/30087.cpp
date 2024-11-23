// 백준: 진흥원 세미나
// https://www.acmicpc.net/problem/30087
// 2024-11-23

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> map = {{"Algorithm", "204"}, {"DataAnalysis", "207"}, {"ArtificialIntelligence", "302"}, {"CyberSecurity", "B101"}, {"Network", "303"},
                                         {"Startup", "501"},   {"TestStrategy", "105"}};

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        cout << map[input] << "\n";
    }
    return 0;
}