#include <iostream>
#include <string>
using namespace std;

int main() {
    string a[7] = {"Never gonna give you up",  "Never gonna let you down", "Never gonna run around and desert you",
                   "Never gonna make you cry", "Never gonna say goodbye",  "Never gonna tell a lie and hurt you",
                   "Never gonna stop"};
    int N;
    cin >> N;
    cin.ignore();
    int temp = true;
    for (int i = 0; i < N && temp; ++i) {
        string b;
        getline(cin, b);
        bool find = false;
        for (int i = 0; i < 7; ++i) {
            if (a[i] == b) {
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}