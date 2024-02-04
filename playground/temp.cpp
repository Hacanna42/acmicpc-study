#include <iostream>
int main() {
    int N;
    std::cout << "셀 숫자를 입력하세요." << std::endl;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cout << i + 1 << " ";
    }
    return 0;
}