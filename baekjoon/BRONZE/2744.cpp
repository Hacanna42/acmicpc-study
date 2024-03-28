#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string answer = "";
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i]))
            answer += tolower(s[i]);
        else
            answer += toupper(s[i]);
    }
    cout << answer;
    return 0;
}