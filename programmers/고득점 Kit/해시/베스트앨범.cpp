#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genre_play_count;
    unordered_map<string, vector<pair<int, int>>> genreSongs; // 장르: 재생횟수, 고유번호

    // 장르별 총 재생 수 계산
    for (int i = 0; i < genres.size(); ++i) {
        genre_play_count[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back({plays[i], i});
    }

    // 정렬 (장르 > 재생 > 고유번호)
    for (auto &[genre, songs] : genreSongs) {
        sort(songs.begin(), songs.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first || (a.first == b.first && a.second < b.second); });
    }

    // 장르를 정렬하기 위해 vector로 변환
    vector<pair<int, string>> genreOrder;
    for (auto &[genre, totalPlay] : genre_play_count) {
        genreOrder.push_back({totalPlay, genre});
    }

    // 장르 재생 횟수 내림차순 정렬
    sort(genreOrder.begin(), genreOrder.end(), [](const pair<int, string> &a, const pair<int, string> &b) { return a.first > b.first; });

    vector<int> answer;

    for (auto &[totalPlay, genre] : genreOrder) {
        auto &songs = genreSongs[genre];
        for (int i = 0; i < songs.size() && i < 2; ++i) {
            answer.push_back(songs[i].second);
        }
    }

    return answer;
}