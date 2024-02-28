#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int weight_num, marble_num;
    cin >> weight_num;
    vector<int> weights(weight_num);
    for (int i = 0; i < weight_num; ++i) {
        cin >> weights[i];
    }
    cin >> marble_num;
    vector<int> marbles(marble_num);
    for (int i = 0; i < marble_num; ++i) {
        cin >> marbles[i];
    }

    return 0;
}