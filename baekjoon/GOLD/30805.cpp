// 백준: 사전 순 최대 공통 부분 수열
// https://www.acmicpc.net/problem/30805
// 2024-06-11

/* 내 풀이:
두 수열 A, B에 대해서
A에서 max_element 를 찾는다 (중복시 제일 앞 인덱스)
B에서 A의 max_element가 나오는 제일 앞 인덱스를 찾는다
if 성공 then 해당 인덱스부터 .end()만 남기고 단계 반복
if 실패 then A의 max_element 바로 다음의 max_element로 재개


풀기 이전의 시행착오들.. :
처음에는 LCS가 바로 생각났다. 규칙을 찾아보니 사전 순 최대 공통 부분 수열은 항상 LCS의 조합으로 만들 수 있었다.
그래서 LCS를 구하고 거기서 그리디적으로 사전 순 최대를 만드는 순서를 찾으면 되는 문제라고 생각했다.
근데 문제는 LCS 역추적에 있었다, LCS는 공통해가 있을 수 있는데 이 모든 루트를 역추적으로 구하려면 재귀적 탐색을 해야했다. **TLE**가 났다.
그냥 naive하게 푸니까 풀리는 것 같다.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

vector<int>::iterator find_max_element_except(vector<int> &T, int start, int except) { // 특정 값을 제외하고 max_element
    if (T.empty())
        return T.end();

    vector<int>::iterator max_it = T.end();
    int max_elem = 0;

    for (vector<int>::iterator it = T.begin() + start; it != T.end(); ++it) {
        if (*it == except)
            *it = -1;
        if (*it > max_elem && *it != except) {
            max_elem = *it;
            max_it = it;
        }
    }

    return max_it;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a_len, b_len; // 수열 A, B 길이
    cin >> a_len;

    vector<int> A(a_len);
    for (int i = 0; i < a_len; ++i) {
        cin >> A[i];
    }
    cin >> b_len;
    vector<int> B(b_len);
    for (int i = 0; i < b_len; ++i) {
        cin >> B[i];
    }

    int prev_max = -1; // 이전 최댓값 (재탐색 방지)
    int A_start_index = 0;
    int B_start_index = 0;
    vector<int> LLCS;
    while (true) {
        auto A_iter = find_max_element_except(A, A_start_index, prev_max); // 제일 처음 등장하는 이전 최댓값을 제외한 최댓값 찾기
        if (A_iter != A.end()) {                                           // 탐색 성공
            // B에서 A의 max_element가 나오는 제일 앞 인덱스를 찾는다
            bool found = false;
            for (int i = B_start_index; i < b_len && !found; ++i) {
                if (B[i] == *A_iter) {                               // 탐색 성공
                    A_start_index = distance(A.begin(), A_iter) + 1; // 수열 A 자르기 (시작 인덱스 조정)
                    B_start_index = i + 1;
                    LLCS.push_back(*A_iter);
                    found = true;
                }
            }
            if (!found) // 탐색 실패 : A의 max_element 바로 다음의 max_element로 재개
                prev_max = *A_iter;
        } else { // A 수열에서 최댓값을 찾을 수 없음 : 종료
            break;
        }
    }

    cout << LLCS.size() << "\n";
    for (const auto &next : LLCS) {
        cout << next << " ";
    }

    return 0;
}