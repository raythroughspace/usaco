#include <bits/stdc++.h>
using namespace std;
void dfs(size_t i, vector<vector<pair<size_t,size_t>>>& adj, vector<size_t>& visited, size_t limit, size_t firs){
    visited[i] = firs;
    for (auto e: adj[i]){
        if (!visited[e.first] && e.second >= limit){
            dfs(e.first, adj, visited, limit, firs);
        }
    }
}

bool is_sortable(vector<vector<pair<size_t,size_t>>>& adj, size_t limit, size_t N, vector<size_t>& locs){
    vector<size_t> visited(N+1);
    for (size_t i=1; i<=N; ++i){
        if (visited[i]){
            continue;
        }
        dfs(i, adj, visited, limit, i);
    }
    bool sortable = true;
    for (size_t i=1; i<=N; ++i){
        if (visited[locs[i]] != visited[i]){
            sortable = false;
        }
    }
    return sortable;
}

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w" ,stdout);
    size_t N,M; cin >> N >> M;
    vector<size_t> locs(N+1);
    for (size_t i=1; i<=N; ++i){
        cin >> locs[i];
    }
    vector<vector<pair<size_t,size_t>>> adj(N+1);
    vector<size_t> weights(M);
    for (size_t i=1; i<=M; ++i){
        size_t a,b,w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        weights[i-1] = w;
    }
    sort(weights.begin(), weights.end());
    ssize_t lo = 0;
    ssize_t hi = M-1;
    ssize_t mid = 0;
    while (lo < hi){
        mid = (hi + lo + 1)/2;
        if (is_sortable(adj, weights[mid], N, locs)){
            //can try higher or equal mid
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    if (is_sortable(adj, INT_MAX, N, locs)){
        cout << -1;
    }
    else{
        cout << weights[lo];
    }
}