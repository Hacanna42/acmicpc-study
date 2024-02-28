#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
/*
3월 1일부터 11월 30일까지
*/

struct Date {
    int month;
    int day;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<Date, Date>> flowers;
    for (int i = 0; i < N; ++i) {
        int start_month, start_day, end_month, end_day;
        cin >> start_month >> start_day >> end_month >> end_day;
        Date start{start_month, start_day};
        Date end{end_month, end_day};
        if (end.month >= 3)
            flowers.push_back({start, end});
    }

    // 꽃이 피는 날짜가 빠른 순으로, 그리고 같은 경우 꽃이 지는 날짜가 늦은 순으로 정렬
    sort(flowers.begin(), flowers.end(), [](pair<Date, Date> &a, pair<Date, Date> &b) {
        if (a.first.month == b.first.month) {
            if (a.first.day == b.first.day) {
                if (a.second.month == b.second.month) {
                    return a.second.day > b.second.day;
                }
                return a.second.month > b.second.month;
            }
            return a.first.day < b.first.day;
        }
        return a.first.month < b.first.month;
    });

    Date current{3, 1};
    Date maxEnd{0, 0};
    int idx = 0;
    int count = 0;

    while (current.month < 12) {
        bool isPossible = false;
        for (int i = idx; i < N; ++i) {
            if ((flowers[i].first.month < current.month) || (flowers[i].first.month == current.month && flowers[i].first.day <= current.day)) {
                if ((flowers[i].second.month > current.month) || (flowers[i].second.month == current.month && flowers[i].second.day > current.day)) {
                    // 선택 가능한 유효한 꽃
                    if (flowers[i].second.month > maxEnd.month) {
                        maxEnd.month = flowers[i].second.month;
                        maxEnd.day = flowers[i].second.day;
                        idx = i;
                        isPossible = true;
                    } else if (flowers[i].second.month == maxEnd.month && flowers[i].second.day > maxEnd.day) {
                        maxEnd.month = flowers[i].second.month;
                        maxEnd.day = flowers[i].second.day;
                        idx = i;
                        isPossible = true;
                    }
                }
            } else {
                break;
            }
        }
        if (!isPossible)
            break;

        // 꽃 찾음
        count++;
        current.month = maxEnd.month;
        current.day = maxEnd.day;
        if (current.month > 11) {
            cout << count;
            return 0;
        }
    }

    // 3월 1일을 포함하고, 지는 날짜가 제일 느린 걸 선택

    // 이전 지는 날짜를 포함하고, 지는 날짜가 제일 느린 걸 선택
    cout << "0";
    return 0;
}