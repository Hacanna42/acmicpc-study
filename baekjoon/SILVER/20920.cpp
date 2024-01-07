// 백준: 영단어 암기는 괴로워
// https://www.acmicpc.net/problem/20920
// 2024-01-07

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<std::string, int> setWordsFreq(
    std::vector<std::string>& wordslist) {
    std::unordered_map<std::string, int> freqOfWords;
    for (const auto& words : wordslist) {
        ++freqOfWords[words];
    }
    return freqOfWords;
}

bool compare(const std::string& a, const std::string& b,
             const std::unordered_map<std::string, int>& freq) {
    if (freq.at(a) != freq.at(b)) {
        return freq.at(a) > freq.at(b);
    }
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    return a < b;
}

int main() {
    int N, len_limit;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<std::string> v;
    std::cin >> N >> len_limit;
    for (int i = 0; i < N; ++i) {
        std::string temp;
        std::cin >> temp;
        if (temp.length() >= len_limit) v.push_back(temp);
    }
    std::unordered_map<std::string, int> freq = setWordsFreq(v);
    std::sort(v.begin(), v.end(),
              [&freq](const std::string& a, std::string& b) {
                  return compare(a, b, freq);
              });

    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());

    for (const auto& iter : v) {
        std::cout << iter << "\n";
    }

    return 0;
}