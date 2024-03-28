#include <chrono>
#include <iomanip>
#include <iostream>

int main() {
    using namespace std;
    using namespace std::chrono;

    auto now = system_clock::now();
    auto current_time = system_clock::to_time_t(now);
    auto local_time = *localtime(&current_time);
    cout << put_time(&local_time, "%Y-%m-%d");

    return 0;
}
