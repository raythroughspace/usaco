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
    vector<vector<size_t>> reverseAdj(N+1);
    for (size_t i=1; i<=M; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        reverseAdj[b].push_back(a);
    }
    vector<bool> visited(N+1);
    vector<bool> reverseVisited(N+1);
    dfs(1, adj, visited);
    dfs(1, reverseAdj, reverseVisited);
    bool answered = false;
    for (size_t i=1; i<=N; ++i){
        if (!visited[i] && !answered){
            cout << "NO\n"<< 1 << " " << i;
            answered = true;
        }
    }
    for (size_t i=1; i<=N; ++i){
        if (!reverseVisited[i] && !answered){
            cout << "NO\n"<< i << " " << 1;
            answered = true;
        }
    }
    if (!answered){
        cout << "YES";
    }
    
}