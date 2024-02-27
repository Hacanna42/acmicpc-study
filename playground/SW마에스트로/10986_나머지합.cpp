#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<ll> prefixNum(N + 1, 0);
    vector<ll> remainderCount(M, 0);
    for (int i = 1; i <= N; ++i) {
        int temp;
        cin >> temp;
        prefixNum[i] = (prefixNum[i - 1] + temp) % M;
        remainderCount[prefixNum[i]]++;
    }

    remainderCount[0]++;

    long long total = 0;
    for (int i = 0; i < M; i++) {
        if (remainderCount[i] > 1) {
            // nC2 조합 공식: n*(n-1)/2
            total += (remainderCount[i] * (remainderCount[i] - 1)) / 2;
        }
    }

    cout << total;
    return 0;
}