// temp

#include <iostream>
#include <string>

using namespace std;

void findAlphabetPositions(const string& word) {
    int positions[26];
    fill_n(positions, 26, -1);

    for (int i = 0; i < word.length(); ++i) {
        int index = word[i] - 'a';
        if (positions[index] == -1) {
            positions[index] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << positions[i] << " ";
    }
}

int main() {
    string word;
    cin >> word;
    findAlphabetPositions(word);

    return 0;
}
