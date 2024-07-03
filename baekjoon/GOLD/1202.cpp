// 백준: 보석 도둑
// https://www.acmicpc.net/problem/1202
// 2024-07-03

/*
가방도 한계 용량 오름차순으로 정렬.
제일 작은 가방 용량부터, 넣을 수 있는 보석을 priority_queue에 추가 .top()을 가방에 넣음.
다음 가방 용량으로 넘어가면서 새롭게 고려 가능해진 보석을 pq에 추가.. 반복
만약 pq를 사용하지 않고 배열을 for로 탐색하면 매 크기의 가방 탐색마다 중복 계산을 감수해야 함
memoization으로도 풀 수 있지 않을까 하는 의문점이 듦.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

ll maximum_value = 0; // 정답 값

struct Gem {
    int weight;
    ll price;

    bool operator<(const Gem &other) const { return price < other.price; }
    // 헷갈리는 부분인데 비교식이 true면 순서를 <유지>
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; // 보석 개수 N
    int K; // 가방 개수 K
    cin >> N >> K;
    vector<Gem> gems(N); // 보석 정보
    for (int i = 0; i < N; ++i) {
        int M, V; // 무게, 가격
        cin >> M >> V;
        gems[i] = {M, V};
    }

    vector<int> bags(K); // 가방 정보
    for (int i = 0; i < K; ++i) {
        int C; // 가방에 담을 수 있는 무게
        cin >> C;
        bags[i] = C;
    }

    sort(gems.begin(), gems.end(), [](const Gem &a, const Gem &b) { return a.weight < b.weight; }); // 보석을 무게 기준으로 오름차순 정렬
    sort(bags.begin(), bags.end());                                                                 // 가방을 용량 기준으로 오름차순 정렬

    priority_queue<Gem> pq; // 현재 가방 용량이 허용하는 가장 가치가 높은 보석을 효율적으로 찾기 위한 우선순위 큐
    int gems_size = gems.size();
    int lastIndex = 0;                   // 탐색 범위를 기록
    for (const auto &cur_limit : bags) { // 용량이 작은 가방부터 탐색 시작
        for (int i = lastIndex; i < gems_size; ++i) {
            int cur_gem_weight = gems[i].weight;
            ll cur_gem_price = gems[i].price;
            if (cur_gem_weight > cur_limit) // 한계 용량을 초과했다면
                break;                      // 우선순위 큐에 삽입 중단

            // 아직 가방에 넣을 수 있는 크기라면: 우선순위 큐에 삽입
            pq.push({cur_gem_weight, cur_gem_price});
            lastIndex = i + 1; // 탐색 범위 업데이트: 이미 고려한 index이므로 다음 인덱스부터 탐색하도록 설정
        }

        // 현재 가방 용량이 허용하는 선의 보석을 모두 우선순위 큐에 추가 완료
        if (pq.empty())
            continue; // 현재 가방 용량에서 고려할 수 있는 보석 없으면 다음 가방으로 스킵

        maximum_value += pq.top().price; // 가장 최상의 값을 정답에 추가
        pq.pop();                        // 가방에 넣은 보석 큐에서 제거
    }

    cout << maximum_value;
}