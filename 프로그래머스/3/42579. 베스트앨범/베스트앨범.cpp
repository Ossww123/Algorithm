#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> num_plays;
    unordered_map<string, vector<pair<int, int>>> genre_songs;
    
    int n = genres.size();
    
    for(int i=0;i<n;i++){
        num_plays[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> sorted_genres;
    for (auto& entry : num_plays){
        sorted_genres.push_back({entry.second, entry.first});
    }
    sort(sorted_genres.begin(), sorted_genres.end(), greater<pair<int, string>>());
    
    for (auto& genre_entry : sorted_genres) {
        string genre = genre_entry.second;
        vector<pair<int, int>>& songs = genre_songs[genre];
        
        sort(songs.begin(), songs.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;  
        });
        
        int count = min(2, (int)songs.size());
        for (int i = 0; i < count; i++) {
            answer.push_back(songs[i].second);
        }
    }
    
    return answer;
}