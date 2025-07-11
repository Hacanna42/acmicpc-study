#include <iostream>
#include <string>
#include <unordered_set>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::unordered_set<char> vowels;

    vowels.insert({'a', 'i', 'e', 'o', 'u'});

    int answer = 0;
    for (int i = 0; i < s.length(); ++i) {
        char cur_s = s[i];
        if (vowels.count(cur_s)) {
            ++answer;
        }
    }

    std::cout << answer;
    return 0;
}