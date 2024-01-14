// 백준: 주유소
// https://www.acmicpc.net/problem/13305
// 2024-01-14

#include <iostream>
#include <vector>
std::vector<long> city_price;
std::vector<long> distance_between_city;
long gas_min_price = 1000000000;
int cities_num;
long long until_arrive = 0;
long long pos_now = 0;
long long current_expenses = 0;

void input();
void greedy();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    input();
    greedy();
    std::cout << current_expenses;
    return 0;
}

void greedy() {
    int city = 0;
    while (city != cities_num - 1) {
        // 현재 지역이 전역에서 가장 싼 곳이라면
        if (city_price[city] <= gas_min_price) {
            current_expenses += (until_arrive - pos_now) * city_price[city];
            break;
            // 도착
        }

        // 아니라면 다음 싼 지역을 찾는다
        bool isCheapCityExist = false;
        for (int i = city + 1; i < cities_num; ++i) {
            // 현재보다 값이 싼 도시를 찾았다면
            if (city_price[i] < city_price[city]) {
                // 그 도시까지 필요한 기름이 몇인지 구한다
                int need = 0;
                for (int j = city; j < i; ++j) {
                    need += distance_between_city[j];
                }
                // 그 도시까지 갈 수 있는 기름을 현재 도시에서 사고 간다
                current_expenses += need * city_price[city];
                city = i;
                pos_now += need;
                isCheapCityExist = true;
                break;
            }
        }

        // 만약 현재 도시가 가장 싼 곳이라면 여기서 남은 기름을 모두 산다.
        if (!isCheapCityExist) {
            current_expenses += (until_arrive - pos_now) * city_price[city];
            break;
            // 도착
        }
    }
}

void input() {
    std::cin >> cities_num;

    // 도시간 거리 입력
    for (int i = 0; i < cities_num - 1; ++i) {
        long distance;
        std::cin >> distance;
        until_arrive += distance;
        distance_between_city.push_back(distance);
    }

    // 도시당 주유 가격 입력
    for (int i = 0; i < cities_num; ++i) {
        long gas_price;
        std::cin >> gas_price;
        if (gas_price < gas_min_price) gas_min_price = gas_price;
        city_price.push_back(gas_price);
    }
}