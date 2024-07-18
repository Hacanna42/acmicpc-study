#include <iostream>
#include <string>
using namespace std;

int main() {
    string t = "WelcomeToSMUPC";
    int n;
    cin >> n;
    cout << t[(n - 1) % 14];
    return 0;
}