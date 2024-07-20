// 백준: 공통 순열
// https://www.acmicpc.net/problem/1622
// 2024-07-20

/*
공통 순열(permutation). 즉 모든 조합에서의 LCS를 구하는 문제.
더 쉽게 말하면: 두 문자열 A, B의 공통 알파벳을 사전순으로 늘어놓는 문제.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    while (!cin.eof()) {
        string A, B;
        cin >> A >> B;
        int size_A = A.size();
        int size_B = B.size();
        vector<bool> visited(B.size(), false);
        vector<char> arr;
        for (int i=0;i<size_A;++i) {
            for (int j=0;j<size_B;++j) {
                if (!visited[j] && A[i] == B[j]) {
                    arr.push_back(A[i]);
                    visited[j] = true;
                    break;
                }
            }
        }

        sort(arr.begin(), arr.end());

        for (const auto& next : arr) {
            cout << next;
        }
        cout << "\n";        
    }
    return 0;
}