#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, vector<bool>& visited, const vector<vector<size_t>>& adj,
            vector<size_t>& component){
    if (visited[i])
        return;
    
    visited[i] = true;
    component.push_back(i);
    for (auto v: adj[i]){
        dfs(v, visited, adj, component);
    }
}
int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    vector<pair<size_t, size_t>> cows(N+1); //coords of cows
    vector<vector<size_t>> adj(N+1);
    for (size_t i=1; i<=N; ++i){
        cin >> cows[i].first >> cows[i].second;
    }
    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    size_t ans = SIZE_MAX;
    vector<bool> visited(N+1);
    for (size_t i=1; i<=N; ++i){
        if (visited[i])
            continue;
        vector<size_t> component;
        dfs(i, visited, adj, component);
        size_t minX = SIZE_MAX, minY = SIZE_MAX;
        size_t maxX = 0, maxY = 0;
        for (auto v: component){
            minX = min(cows[v].first, minX);
            maxX = max(cows[v].first, maxX);
            minY = min(cows[v].second, minY);
            maxY = max(cows[v].second, maxY);
        }
        ans = min(ans, 2*(maxY - minY) + 2*(maxX - minX));
    }
    cout << ans;
}