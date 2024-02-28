#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll N, C;
    cin >> N >> C;
    vector<ll> houses(N);
    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    ll minDist = 1;
    ll maxDist = houses[N - 1] - houses[0];
    ll result = 0;

    while (minDist <= maxDist) {
        ll midDist = (minDist + maxDist) / 2;
        ll lastInstalled = houses[0];
        ll installed = 1;
        for (int i = 1; i < N; ++i) {
            if (houses[i] - lastInstalled >= midDist) {
                installed++;
                lastInstalled = houses[i];
            }
        }

        if (installed >= C) {
            result = max(result, midDist);
            minDist = midDist + 1;
        } else {
            maxDist = midDist - 1;
        }
    }

    cout << result;
    return 0;
}