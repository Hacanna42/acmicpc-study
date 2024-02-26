#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int calendar[13][32];
    int month = 1;
    int day = 1;
    int last_day_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int week_counter = 0; // 월 화 수 목 금 토 일
    string week_str[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    while (month != 13) {
        calendar[month][day] = week_counter % 7;
        ++week_counter;
        if (++day > last_day_of_month[month]) {
            month++;
            day = 1;
        }
    }

    int x, y;
    cin >> x >> y;
    cout << week_str[calendar[x][y]];

    return 0;
}