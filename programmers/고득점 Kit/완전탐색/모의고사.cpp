#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int man1[5] = {1, 2, 3, 4, 5};
    int man2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int man3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int man1_count = 0;
    int man2_count = 0;
    int man3_count = 0;
    for (int i = 0; i <= 10000 && i < answers.size(); ++i) {
        int man1_next = man1[i % 5];
        int man2_next = man2[i % 8];
        int man3_next = man3[i % 10];

        if (answers[i] == man1_next)
            ++man1_count;
        if (answers[i] == man2_next)
            ++man2_count;
        if (answers[i] == man3_next)
            ++man3_count;
    }

    int max_count = max({man1_count, man2_count, man3_count});
    vector<int> answer;
    if (max_count == man1_count)
        answer.push_back(1);
    if (max_count == man2_count)
        answer.push_back(2);
    if (max_count == man3_count)
        answer.push_back(3);
    return answer;
}