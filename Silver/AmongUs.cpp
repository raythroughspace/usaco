#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, const vector<vector<pair<size_t,size_t>>>& adj, vector<ssize_t>& visited, 
    ssize_t label, bool& consistent, size_t& nhumans, size_t& component_size){
    if (visited[i])
        return;
    visited[i] = label;
    ++component_size;
    if (label == 1)
        ++nhumans;
    for (const auto [j, type]: adj[i]){
        if (type == 1){
            if (visited[i] == visited[j])
                consistent = false;
            
            dfs(j, adj, visited, -label, consistent, nhumans, component_size);
        }
        if (type == 2){
            if (visited[j] && visited[i] != visited[j])
                consistent = false;
            dfs(j, adj, visited, label, consistent, nhumans, component_size);
        }
    }
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,Q; cin >> N >> Q;
        vector<vector<pair<size_t,size_t>>> adj(N+1);
        for (size_t q=0; q<Q; ++q){
            size_t type,i,j; cin >> type >> i >> j;
            adj[i].push_back({j, type});
            adj[j].push_back({i, type});
        }
        size_t ans = 0;
        bool consistent = true;
        vector<ssize_t> visited(N+1); // visited[i] = 1 or -1 for H or P
        for (size_t i=1; i<=N; ++i){
            size_t nhumans = 0;
            size_t component_size = 0;
            dfs(i, adj, visited, 1, consistent, nhumans, component_size);
            ans += max((component_size - nhumans), nhumans);
        }
        if (consistent){
            cout << ans << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}