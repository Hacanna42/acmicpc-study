#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> s = {1, 2, 3, 4, 5};
    // 문자열을 사전순으로 정렬
    std::sort(s.begin(), s.end());
    do {
        for (const int next : s) {
            std::cout << next << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(s.begin(), s.end()));
    return 0;
}