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
    size_t N,M; cin >> N >> M;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(N+1);
    vector<size_t> ans;
    for (size_t i=1; i<=N; ++i){
        if (!visited[i]){
            ans.push_back(i);
            dfs(i, adj, visited);
        }
    }
    cout << ans.size() - 1 << "\n";
    for (size_t i=1; i<ans.size(); ++i){
        cout << ans[0] << " " << ans[i] << "\n";
    }
}