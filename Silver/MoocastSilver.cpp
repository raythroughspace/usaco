#include <bits/stdc++.h>
using namespace std;
void dfs(size_t i, vector<vector<size_t>>& adj, vector<bool>& visited){
    visited[i] = true;
    for (auto e: adj[i]){
        if (!visited[e]){
            dfs(e, adj, visited);
        }
    }
}
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<ssize_t,ssize_t>> idx2pair(N);
    vector<vector<size_t>> adj(N);
    vector<size_t> powers(N);
    for (size_t i=0; i<N; ++i){
        cin >> idx2pair[i].first >> idx2pair[i].second >> powers[i];
    }
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            if (i==j){
                continue;
            }
            if ((idx2pair[i].first - idx2pair[j].first)*(idx2pair[i].first - idx2pair[j].first)
            + (idx2pair[i].second - idx2pair[j].second)*(idx2pair[i].second - idx2pair[j].second) <= powers[i]*powers[i]){
                adj[i].push_back(j);
            }
        }
    }
    size_t ans = 0;
    for (size_t i=0; i<N; ++i){
        vector<bool> visited(N);
        dfs(i, adj, visited);
        size_t num = 0;
        for (size_t j=0; j<N; ++j){
            if (visited[j]){
                ++num;
            }
        }
        ans = max(ans, num);
    }
    cout << ans;

}