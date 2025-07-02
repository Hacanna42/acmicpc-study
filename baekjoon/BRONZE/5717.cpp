#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true) {
        int M, F;
        std::cin >> M >> F;
        if (M + F == 0) {
            return 0;
        }

        std::cout << M + F << "\n";
    }
    return 0;
}