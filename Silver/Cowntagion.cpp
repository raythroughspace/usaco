#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, vector<bool>& visited, const vector<vector<size_t>>& adj, 
ssize_t& days){
    visited[i] = true;
    size_t cows = 1;
    size_t farms = adj[i].size();
    if (i==1){
        farms++;
    }
    while (cows < farms){
        ++days;
        cows *= 2;
    }
    for (const auto& v: adj[i]){
        if (visited[v]){
            continue; // v is parent
        }
        ++days;
        dfs(v, visited, adj, days);
    }
}

int main(){
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<N-1; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ssize_t days = 0;
    vector<bool> visited(N+1);
    dfs(1, visited, adj, days);
    cout << days;
}