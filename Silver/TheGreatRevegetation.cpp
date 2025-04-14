#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, const vector<vector<pair<size_t,char>>>& adj, 
    vector<ssize_t>& visited, size_t color, bool& possible){
    if (visited[i])
        return;
    
    visited[i] = color;
    for (const auto [j, c]: adj[i]){
        if (c == 'S'){
            if (visited[j] != visited[i] && visited[j] != 0){
                possible = false;
            }
            dfs(j, adj, visited, color, possible);
        }
        else{
            if (visited[j] == visited[i]){
                possible = false;
            }
            dfs(j, adj, visited, -color, possible);
        }
    }
}

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    vector<vector<pair<size_t, char>>> adj(N+1);
    for (size_t i=0; i<M; ++i){
        char c; size_t a,b; cin >> c >> a >> b;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    size_t connected_components = 0;
    bool possible = true; // if it's possible at all to plant grass to satisfy constraint
    vector<ssize_t> visited(N+1);
    for (size_t i=1; i<=N; ++i){
        if (visited[i]==0){
            dfs(i, adj, visited, 1, possible);
            ++connected_components;
        }
    }
    if (possible){
        cout << "1";
        for (size_t i=0; i<connected_components; ++i)
            cout << "0";
    }
    else{
        cout << "0";
    }
}