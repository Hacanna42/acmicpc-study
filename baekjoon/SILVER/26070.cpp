// 백준: 곰곰이와 학식
// https://www.acmicpc.net/problem/26070
// 2024-02-20

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long A, B, C, X, Y, Z;
    cin >> A >> B >> C;
    cin >> X >> Y >> Z;

    long long fed = 0;

    // 식권 바로 사용
    long long minChicken = min(A, X);
    A -= minChicken;
    X -= minChicken;
    fed += minChicken;

    long long minPizza = min(B, Y);
    B -= minPizza;
    Y -= minPizza;
    fed += minPizza;

    long long minBurger = min(C, Z);
    C -= minBurger;
    Z -= minBurger;
    fed += minBurger;

    while (true) {
        bool exchanged = false;

        // 치킨 식권을 피자 식권으로 교환
        while (X >= 3) {
            X -= 3;
            // B--;
            Y++;
            // fed++;
            exchanged = true;
        }

        // 피자 식권 사용
        while (Y > 0 && B > 0) {
            Y--;
            B--;
            fed++;
            exchanged = true;
        }

        // 피자 식권을 햄버거 식권으로 교환
        while (Y >= 3) {
            Y -= 3;
            // C--;
            Z++;
            // fed++;
            exchanged = true;
        }

        // 햄버거 식권 사용
        while (Z > 0 && C > 0) {
            Z--;
            C--;
            fed++;
            exchanged = true;
        }

        // 햄버거 식권을 치킨 식권으로 교환
        while (Z >= 3) {
            Z -= 3;
            // A--;
            X++;
            // fed++;
            exchanged = true;
        }

        // 치킨 식권 사용
        while (X > 0 && A > 0) {
            X--;
            A--;
            fed++;
            exchanged = true;
        }

        if (!exchanged)
            break;
    }

    cout << fed;

    return 0;
}
