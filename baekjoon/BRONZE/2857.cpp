// 백준: FBI
// https://www.acmicpc.net/problem/2857
// 2024-01-31
// 업다운 디펜스 디버깅용

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> fbis;
    for (int i = 1; i <= 5; ++i) {
        std::string name;
        std::cin >> name;

        // FBI 요원인지 확인
        if (name.find("FBI") != std::string::npos) {
            fbis.push_back(i);
        }
    }

    if (fbis.empty()) {
        std::cout << "HE GOT AWAY!"
                  << "\n";
    } else {
        for (int agent : fbis) {
            std::cout << agent << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
