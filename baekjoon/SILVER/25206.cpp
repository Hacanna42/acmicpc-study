// 백준: 너의 평점은
// https://www.acmicpc.net/problem/25206
// 2023-12-20

// EOF, line 입력받기
// line을 공백으로 구분, [1]번째와 [2]번째가 있음
// [2]번째는 표에 따라서 float으로 변환
// (학점 × 과목평점) / 학점총합 = 전공평점

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

float getScore(std::string grade) {
    if (grade == "A+") {
        return 4.5f;
    } else if (grade == "A0") {
        return 4.0f;
    } else if (grade == "B+") {
        return 3.5f;
    } else if (grade == "B0") {
        return 3.0f;
    } else if (grade == "C+") {
        return 2.5f;
    } else if (grade == "C0") {
        return 2.0f;
    } else if (grade == "D+") {
        return 1.5f;
    } else if (grade == "D0") {
        return 1.0f;
    } else if (grade == "F") {
        return 0.0f;
    }
    return 0.0f;
}

int main() {
    std::vector<std::string> lines;
    std::string line;
    int scores = 0;
    float scoreXaverage = 0.0f;
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
        std::stringstream ss(lines[i]);
        std::string subject, score, grade;
        ss >> subject >> score >> grade;
        if (grade != "P") {
            scores += std::stof(score);
            scoreXaverage += std::stof(score) * getScore(grade);
        }
    }
    std::cout << scoreXaverage / scores;
    return 0;
}