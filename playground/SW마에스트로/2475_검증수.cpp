#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << static_cast<int>((pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2))) % 10;
    return 0;
}