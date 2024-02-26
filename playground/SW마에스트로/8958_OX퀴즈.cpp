#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    cin.ignore();
    for (int i = 0; i < TC; ++i) {
        int answer = 0;
        string temp;
        getline(cin, temp);
        int counter = 0;
        for (int j = 0; j < temp.size(); ++j) {
            if (temp[j] == 'O') {
                answer += ++counter;
            } else {
                counter = 0;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}