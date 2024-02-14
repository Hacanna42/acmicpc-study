#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> &numbers, int current, int target, int depth = 0) {
    int count = 0;
    if (depth == numbers.size()) {
        if (current == target)
            return 1;
        else
            return 0;
    }

    count += dfs(numbers, current - numbers[depth], target, depth + 1);
    count += dfs(numbers, current + numbers[depth], target, depth + 1);

    return count;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer += dfs(numbers, 0, target);
    return answer;
}