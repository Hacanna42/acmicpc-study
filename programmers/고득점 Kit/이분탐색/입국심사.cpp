#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    ll minTime = *min_element(times.begin(), times.end());
    ll maxTime = *max_element(times.begin(), times.end()) * n;

    while (minTime <= maxTime) {
        ll midTime = (minTime + maxTime) / 2;
        ll people = 0;
        for (const auto &time : times) {
            people += midTime / time;
        }

        if (people >= n) {
            answer = midTime;
            maxTime = midTime - 1;
        } else if (people < n) {
            minTime = midTime + 1;
        }
    }
    return answer;
}