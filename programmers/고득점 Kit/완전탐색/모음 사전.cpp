#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> weights = {781, 156, 31, 6, 1};
    vector<char> characters = {'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < word.length(); i++) {
        for (int j = 0; j < characters.size(); j++) {
            if (word[i] == characters[j]) {

                answer += 1 + j * weights[i];
                break;
            }
        }
    }

    return answer;
}