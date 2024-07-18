// 백준: 아무래도이문제는A번난이도인것같다
// 2024-07-18
// https://www.acmicpc.net/problem/1402

/*
어떤 정수 A가 있으면 그 수를 A = a1 * a2 * a3 * a4 ... 라고 했을 때
a1, a2, a3, a4는 무조건 A의 약수들로 이루어져있다.
왜냐하면 A를 구성하는 곱에 A의 약수가 아닌 수가 포함되어 있다면, A를 나눌 수 없기에 A를 구성하는 곱으로 성립할 수 없다.

PS. 문제를 풀며 의아했었다, A의 약수 조합을 생성하려면 DFS + 백트래킹을 사용해야 하는데... 그런 문제가 실버 V일 리는 없기 때문에.. 뭔가 이상했다
결론은 A(i)의 제한이 정수이기 때문에, 음수도 가능하고 -1을 계속 곱하는 식으로 모든 A를 B로 바꾸는 게 가능하다.
따라서 이 문제는 알고리즘 집어 치우고.. 모든 케이스에 "yes"를 출력하면 되는 문제.
아이디어가 재밌다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << "yes\n";
        // // A의 모든 약수를 찾는다.
        // vector<int> divisors;
        // for (int i = 1; i * i <= A; ++i) {
        //     if (A % i == 0) {
        //         divisors.push_back(i);
        //         if (i != A / i)
        //             divisors.push_back(A / i);
        //     }
        // }
    }
    return 0;
}