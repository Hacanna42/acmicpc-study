// 백준: 약수들의 합
// https://www.acmicpc.net/problem/9506
// 2023-12-22

#include <iostream>
#include <vector>
int main() {
    int n;
    std::vector<int> divisor_list;
    while (true) {
        int sum = 0;
        std::cin >> n;
        if (n != -1) {
            divisor_list.clear();
            for (int i = 1; i < n; i++) {
                if (n % i == 0) {
                    divisor_list.push_back(i);
                    sum += i;
                }
            }
            if (sum == n) {  // n은 완전수임.
                std::cout << sum << " = ";
                for (int i = 0; i < divisor_list.size(); i++) {
                    if (i != divisor_list.size() - 1)
                        std::cout << divisor_list[i] << " + ";
                    else
                        std::cout << divisor_list[i] << std::endl;
                }
            } else  // 완전수가 아님
                std::cout << n << " is NOT perfect." << std::endl;
        } else
            break;
    }
    return 0;
}