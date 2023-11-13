// 모두의코드 4-1
// https://modoocode.com/172
// 2023-11-07

#include <iostream>

class Date {
   private:
    int year_;
    int month_;
    int day_;

    bool IsValidDate(int year, int month, int day) {
        if (year < 0) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > getDaysInMonth(year, month)) return false;
        return true;
    }

    bool IsLeapYear(int year) {
        // 윤년 판단: 4로 나누어 떨어지면서, 100으로 나누어 떨어지지 않거나,
        // 400으로 나누어 떨어지면 윤년
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getDaysInMonth(int year, int month) {
        switch (month) {
            case 2:
                return IsLeapYear(year) ? 29 : 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                return 31;
        }
    }

   public:
    void setDate(int year, int month, int day) {
        if (IsValidDate(year, month, day)) {
            year_ = year;
            month_ = month;
            day_ = day;
        } else {
            std::cout << "DATE IS UNVALID. EXIT PROGRAM." << std::endl;
            throw "Exception";
        }
    }
    void AddDay(int how) {
        day_ += how;
        while (day_ > getDaysInMonth(year_, month_)) {
            day_ -= getDaysInMonth(year_, month_);
            AddMonth(1);
        }
    }
    void AddMonth(int how) {
        month_ += how;
        while (month_ > 12) {
            month_ -= 12;
            AddYear(1);
        }
        AddDay(0);  // 월이 바뀌면, 원래의 일수가 n월엔 유효하지 않을 수 있으니
                    // 예외처리
    }
    void AddYear(int how) { year_ += how; }
    void ShowDate() {
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일."
                  << std::endl;
    }
};

int main() {
    int year;
    int month;
    int day;
    Date date;
    std::cout << "년도 입력 : ";
    std::cin >> year;
    std::cout << "월 입력 : ";
    std::cin >> month;
    std::cout << "일 입력 : ";
    std::cin >> day;

    date.setDate(year, month, day);

    for (;;) {
        int temp;
        int how;
        std::cout << "1. AddYear\n2. AddMonth\n3. AddDay" << std::endl;
        std::cin >> temp;
        std::cout << "How? : ";
        std::cin >> how;
        switch (temp) {
            case 1:
                date.AddYear(how);
                break;
            case 2:
                date.AddMonth(how);
                break;
            case 3:
                date.AddDay(how);
                break;
            default:
                std::cout << "error" << std::endl;
        }

        date.ShowDate();
    }

    return (0);
}