// 백준: 잃어버린 괄호
// https://www.acmicpc.net/problem/1541
// 2024-01-14

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokens;
    size_t pos = 0;
    while (pos != std::string::npos) {
        size_t nextPos = input.find_first_of("+-", pos);
        if (nextPos != std::string::npos) {
            tokens.push_back(input.substr(pos, nextPos - pos));
            tokens.push_back(input.substr(nextPos, 1));
        } else
            tokens.push_back(input.substr(pos));
        pos = (nextPos != std::string::npos) ? nextPos + 1 : nextPos;
    }

    // 마이너스 뒤의 모든 항을 다른 마이너스가 나올때까지 마이너스로 변경
    bool placeHolder = false;
    for (int i = 1; i < tokens.size(); i += 2) {
        if (tokens[i] == "-") {
            placeHolder = true;
        } else if (tokens[i] == "+" && placeHolder)
            tokens[i] = "-";
    }

    int sum = 0;
    for (int i = tokens.size() - 1; i >= 0; i -= 2) {
        int num = std::stoi(tokens[i]);
        if (i == 0) {
            sum += num;
            break;
        }
        if (tokens[i - 1] == "+") {
            sum += num;
        } else if (tokens[i - 1] == "-") {
            sum -= num;
        }
    }

    std::cout << sum;
    return 0;
}