#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, N;
    cin >> K >> N;
    vector<int> wires(K);
    for (int i = 0; i < K; ++i) {
        cin >> wires[i];
    }

    ll minLength = 1;
    ll maxLength = *max_element(wires.begin(), wires.end());
    ll answer = 0;

    while (minLength <= maxLength) {
        ll midLength = minLength + (maxLength - minLength) / 2;
        ll count = 0;
        for (const auto &wire : wires) {
            count += wire / midLength;
        }

        if (count >= N) { // 랜선이 목표보다 많거나 같다면
            minLength = midLength + 1;
            answer = midLength;
        } else { // 랜선이 목표보다 작다면
            maxLength = midLength - 1;
        }
    }

    cout << answer;
    return 0;
}