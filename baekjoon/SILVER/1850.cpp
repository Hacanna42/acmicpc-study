// 백준: 최대공약수
// https://www.acmicpc.net/problem/1850
// 2024-04-07

/*
포인트는, 숫자 자체에 초점을 맞추는 게 아니라 1의 개수에 초점을 맞추는 것
두 수 A와 B가 모두 1로만 이루어져 있으므로, 최대공약수도 1로만 이루어진 수가 된다.
A와 B의 최대공약수는 A와 B의 길이(1의 개수)의 최대공약수와 같다.
따라서 '1'을 gcd(a, b)번 반복한게 답이 된다.
*/

#include <iostream>
#include <numeric>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    ll loop = gcd(a, b);
    while (loop--) {
        cout << "1";
    }
    return 0;
}