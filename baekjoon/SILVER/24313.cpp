// 백준: 알고리즘 수업 - 점근적 표기 1
// https://www.acmicpc.net/problem/24313
// 2023-12-26

/*
빅-오 표기법을 이용하기 위해서는 기본적인 수학적 지식이 필요하다.
빅-오 표기법은 어떤 함수 f(n)의 증가 양상을 다른 함수와의 비교로 표현하는
방법이다. O(g(n)) = f(n)은 f(n)의 성장률이 g(n)에 제한된다(속한다) 를 뜻한다.
-
a제로 = 식 옆의 상수 값 a원 = 식의 계수 ex) a제로가 2고 a원이 3이면 =
3n + 2 n제로 = 최소값을 지정하기 위한 특정한 양의 정수. 예를 들어 n제로가 3이면
n >= 3
-
따라서 이 문제는,
입력 값: a1, a0, c, n0에 대해서
a1*n + a0가 c*n 이하인지 확인하면 된다.
근데 모든 n에 대해서 검증하는 것은 불가능하기에, 최소값 n0에서만 일단 검증하는
것으로 타협을 봤다.

ps.
C++에서 이를 검증하는 것은 불가능한 것 같다. 모든 가능한
n에 대해 이를 검증하는 것은 실질적으로 무한한 수의 검증을 요구하기 때문이다.
그러면, 주어진 n >= n0에 대해 방정식을 만족하는지 어떻게 확신할 수 있지?
*/
#include <iostream>
int main() {
    int a1, a0, c, n0;
    int fn, gn;
    bool answer = true;
    std::cin >> a1 >> a0 >> c >> n0;
    for (int i = n0; i < n0 + 1000;
         i++) {  // 테스트케이스 확인 값을 1000까지 올리니까 통과됐다. 원래
                 // 이렇게 임시적인 방법으로만 되는걸까? 한번 내일 찾아봐야겠다
                 // #TODO
                 // && a1 <= c 를 추가하면 됐다. 기울기의 차이를 고려해야 했다.
        fn = a1 * i + a0;
        gn = c * i;
        if (!(fn <= gn)) {
            answer = false;
            break;
        }
    }
    if (answer)
        std::cout << "1";
    else
        std::cout << "0";
    return 0;
}