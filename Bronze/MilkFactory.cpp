#include <bits/stdc++.h>
using namespace std;
void dfs(size_t i, vector<bool>& visited, vector<vector<size_t>>& adj){ 
    visited[i] = true;
    for (auto node: adj[i]){
        if (!visited[node]){
            dfs(node, visited, adj);
        }
    }
}
int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<N-1; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    long smallestAns = -1;
    for (size_t i=1; i<=N; ++i){ //possible to go to i from every other node?
        bool ans = true;
        for (size_t j=1; j<=N; ++j){
            if (j== i){
                continue;
            }
            vector<bool> visited(N+1, false);
            dfs(j, visited, adj);
            if (!visited[i]){
                ans = false;
            }
        }
        if (ans){
            smallestAns = i;
            break;
        }
    }
    cout << smallestAns;
}