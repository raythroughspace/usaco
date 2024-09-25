#include <bits/stdc++.h>
using namespace std;
void dfs(size_t i, const vector<vector<pair<size_t,size_t>>>& adj, vector<bool>& visited,
vector<vector<size_t>>& dist, size_t start, multiset<size_t>& minEl){
    if (visited[i]){
        return;
    }
    visited[i] = true;
    if (start != i){
        dist[start][i] = *minEl.begin();
    }
    for (auto p: adj[i]){
        minEl.insert(p.second);
        dfs(p.first, adj, visited, dist, start, minEl);
        minEl.erase(minEl.lower_bound(p.second));
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
    vector<vector<size_t>> dist(N+1, vector<size_t>(N+1));
    for (size_t i=1; i<=N; ++i){
        vector<bool> visited(N+1);
        multiset<size_t> minEl;
        dfs(i, adj, visited, dist, i, minEl);
    }

    for (size_t q=0; q<Q; ++q){
        size_t k, v; cin >> k >> v;
        size_t ans = 0;
        for (size_t i=1; i<=N; ++i){
            if (i== v){
                continue;
            }
            if (dist[v][i] >= k){
                ++ans;
            }
        }
        cout << ans << "\n";
    }
}