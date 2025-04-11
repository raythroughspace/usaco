#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, const vector<vector<pair<size_t,size_t>>>& adj, vector<bool>& visited, size_t k){
    if (visited[i])
        return;
    visited[i] = true;
    for (const auto& [v,r]: adj[i]){
        if (r >= k){
            dfs(v, adj, visited, k);
        }
    }
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    size_t N,Q; cin >> N >> Q;
    vector<vector<pair<size_t,size_t>>> adj(N+1);
    for (size_t i=0; i<N-1; ++i){
        size_t p,q,r; cin >> p >> q >> r;
        adj[p].push_back({q,r});
        adj[q].push_back({p,r});
    }
    for (size_t q=0; q<Q; ++q){
        size_t k,v; cin >> k >> v;
        vector<bool> visited(N+1);
        dfs(v, adj, visited, k);
        size_t ans = 0;
        for (size_t i=1; i<=N; ++i){
            if (visited[i] && i != v)
                ++ans;
        }
        cout << ans << "\n";
    }
}