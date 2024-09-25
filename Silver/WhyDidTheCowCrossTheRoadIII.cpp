#include <bits/stdc++.h>
using namespace std;

void flood_fill(ssize_t i, ssize_t j, size_t N,
vector<vector<set<pair<size_t,size_t>>>>& blocked, vector<vector<size_t>>& visited, size_t color){
    if (i < 0 || i > N-1 || j<0 || j>N-1 || visited[i][j]){
        return;
    }
    visited[i][j] = color;
    if (!blocked[i][j].count({i+1, j})){
        flood_fill(i+1, j, N, blocked, visited, color);
    }
    if (!blocked[i][j].count({i, j+1})){
        flood_fill(i, j+1, N, blocked, visited, color);
    }
    if (!blocked[i][j].count({i, j-1})){
        flood_fill(i, j-1, N, blocked, visited, color);
    }
    if (!blocked[i][j].count({i-1, j})){
        flood_fill(i-1, j, N, blocked, visited, color);
    }
}
int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    size_t N,K,R; cin >> N >> K >> R;
    vector<vector<set<pair<size_t,size_t>>>> blocked(N, vector<set<pair<size_t,size_t>>>(N));
    for (size_t i=0; i<R; ++i){
        size_t a,b,c,d; cin >> a >> b >> c >> d;
        blocked[a-1][b-1].insert({c-1,d-1});
        blocked[c-1][d-1].insert({a-1, b-1});
    }
    vector<vector<size_t>> visited(N, vector<size_t>(N)); //vertices will be colored by component
    vector<pair<size_t,size_t>> cows(K);
    for (size_t i=0; i<K; ++i){
        size_t a,b; cin >> a >> b;
        cows[i].first = a-1;
        cows[i].second = b-1;
    }
    size_t color = 0;
    for (ssize_t i=0; i<N; ++i){
        for (ssize_t j=0; j<N; ++j){
            if (!visited[i][j]){
                ++color;
                flood_fill(i, j, N, blocked, visited, color);
            }
        }
    }
    size_t ans = 0;
    for (size_t i=0; i<K; ++i){
        for (size_t j=i+1; j<K; ++j){
            if (visited[cows[i].first][cows[i].second] != visited[cows[j].first][cows[j].second]){
                ++ans;
            }
        }
    }
    cout << ans;

}