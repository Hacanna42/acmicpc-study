// 백준: 분수찾기
// https://www.acmicpc.net/problem/1193
// 2023-12-21

/*
패턴을 찾는 게 생각보다 힘들다. 분수를 그냥 슬래쉬를 제거하고 정수로 가정하면
+1은 가로 한칸 이동마다. +10은 세로 한칸 이동마다 발생하고.
처음엔 1, 2, 3, 4, 5 식으로 +9와 -9가 번갈아가면서 발생한다.
2, 4, 7, 11, 16, 22. 이차수열식으로 세로나 가로이동이 번갈아가면서 발생함
*/
#include <cmath>
#include <iostream>
#include <utility>

bool isInQuadraticSequence(int i) {
    double discriminant = sqrt(1 + 8 * (i - 1));

    // 판별식이 음수라면 실수 해가 없으므로, false 반환
    if (discriminant < 0) {
        return false;
    }

    double n1 = (-1 + discriminant) / 2;
    double n2 = (-1 - discriminant) / 2;

    // n1 또는 n2 중 하나라도 양의 정수이면 true 반환
    return (n1 > 0 && floor(n1) == n1) || (n2 > 0 && floor(n2) == n2);
}

int main() {
    int numerator = 1, denominator = 1;
    int n = 0;
    int pacemaker = 0;
    std::cin >> n;
    for (int i = 2; i <= n; i++) {
        // 세로 및 가로 이동 (이차수열)마다 번갈아가며 +1, +10.
        if (isInQuadraticSequence(i)) {
            if (pacemaker == 0) {
                denominator++;
                pacemaker = 1;
            } else {
                numerator++;
                pacemaker = 0;
            }
        }
        // 이차수열이 아니라면 번갈아가면서 +9, -9.
        else {
            if (pacemaker == 1) {
                numerator++;
                denominator--;
            } else {
                numerator--;
                denominator++;
            }
        }
    }
    std::cout << numerator << "/" << denominator;
    return 0;
}

/*
수학을 잘 못해서 많이 어려웠다. 패턴을 찾는것도 쉽지 않았고. 이차수열의 방정식도
쉽지 않았다. 처음엔 로직을 단순화하기 위해서 분자와 분모를 나누지 않고 그냥
하나의 int형으로 취급했는데.
어느정도 감 잡고 구현하다가 중간에 수가 커지면 오류가 생길 것 같아서
중간에 분자/분모로 바꿨다.
*/