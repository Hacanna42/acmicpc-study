// 백준: 집합
// https://www.acmicpc.net/problem/11723
// 2024-01-19

#include <iostream>
// #include <sstream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int S = 0;
    int M, x;
    std::string command;
    // std::ostringstream oss;

    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> x;
            S |= (1 << (x - 1));
        } else if (command == "remove") {
            std::cin >> x;
            S &= ~(1 << (x - 1));
        } else if (command == "check") {
            std::cin >> x;
            std::cout << ((S & (1 << (x - 1))) ? 1 : 0) << "\n";
        } else if (command == "toggle") {
            std::cin >> x;
            // if ((S & (1 << (x - 1)))) {
            //     S &= ~(1 << (x - 1));
            // } else {
            //     S |= (1 << (x - 1));
            // }
            S ^= (1 << (x - 1));

        } else if (command == "all") {
            // S = 0;
            S = (1 << 20) - 1;
        } else if (command == "empty") {
            S = 0;
        }
    }

    // std::cout << oss.str();

    return 0;
}
