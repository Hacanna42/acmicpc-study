// 백준: 편의점 2
// https://www.acmicpc.net/problem/14400
// 2024-07-15

/*
1차원에서 모든 좌표간의 거리 합이 최소가 되는 위치는 중간 값일 것이다.
즉 모든 x좌표를 더하고 2로 나눈 값이 중간 값이 된다. (수학)

이를 확장해서, 2차원에서의 중간값은 x와 y를 별개로 생각하면 된다.
배열의 크기가 홀수일 경우에는 중간 값을, 짝수면 중간 값 두개의 중간 값을 구한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr_x(n, 0);
    vector<int> arr_y(n, 0);
    for (int i=0;i<n;++i) {
        cin >> arr_x[i] >> arr_y[i];
    }

    // x, y 값 정렬
    sort(arr_x.begin(), arr_x.end());
    sort(arr_y.begin(), arr_y.end());


    // 중앙값 계산: 문제의 정의가 맨해튼 거리이므로, 그냥 중앙값을 선택해도 문제 없음
    int mid_x = arr_x[n/2];
    int mid_y = arr_y[n/2];



    ll answer = 0;
    for (int i=0;i<n;++i) {
        answer += abs(arr_x[i] - mid_x);
        answer += abs(arr_y[i] - mid_y);
    }

    cout << answer;

    
    return 0;
}