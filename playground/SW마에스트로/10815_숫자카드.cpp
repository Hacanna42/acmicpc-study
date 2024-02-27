#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int temp;
        cin >> temp;
        if (s.find(temp) != s.end()) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    return 0;
}