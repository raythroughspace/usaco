#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, size_t X, vector<bool>& visited, vector<vector<pair<size_t,size_t>>>& adj){
    visited[i] = true;
    for (auto e: adj[i]){
        if (!visited[e.first] && e.second <= X){
            dfs(e.first, X, visited, adj);
        }
    }
}
bool is_connected(size_t X, size_t N, vector<vector<pair<size_t,size_t>>>& adj){
    vector<bool> visited(N);
    dfs(0, X, visited, adj);
    for (size_t i=0; i<N; ++i){
        if (!visited[i]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<ssize_t,ssize_t>> cows(N);
    for (size_t i=0; i<N; ++i){
        cin >> cows[i].first >> cows[i].second;
    }
    vector<vector<pair<size_t,size_t>>> adj(N);
    vector<size_t> distList;
    for (size_t i=0; i<N; ++i){
        for (size_t j=i+1; j<N; ++j){
            ssize_t dist = (cows[i].first - cows[j].first)*(cows[i].first - cows[j].first)
                        + (cows[i].second - cows[j].second)*(cows[i].second - cows[j].second);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
            distList.push_back(dist);
        }
    }
    sort(distList.begin(), distList.end());
    size_t lo = 0;
    size_t hi = distList.size();
    while (lo < hi){
        size_t mid = (hi + lo)/2;
        if (is_connected(distList[mid], N, adj)){
            // can go lower
            hi = mid;
        }
        else{
            // need to go higher
            lo = mid + 1;
        }
    }
    cout << distList[lo];
}