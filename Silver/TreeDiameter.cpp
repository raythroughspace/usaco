#include <bits/stdc++.h>
using namespace std;

void dfs(const size_t i, size_t distance, pair<size_t,size_t> &maxDist, vector<bool>& visited, 
const vector<vector<size_t>>& adj){
    if (visited[i]){
        return;
    }
    visited[i] = true;
    if (distance > maxDist.first){
        maxDist = {distance, i};
    }
    for (auto node: adj[i]){
        ++distance;
        dfs(node, distance, maxDist, visited, adj);
        --distance;
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
    vector<bool> visited(N+1);
    size_t distance = 0;
    pair<size_t,size_t> maxDist = {0, 1}; // {dist, node}
    dfs(1, distance, maxDist, visited, adj);
    //reset values 
    maxDist.first = 0;
    fill(visited.begin(), visited.end(), false);
    dfs(maxDist.second, distance, maxDist, visited, adj);
    cout << maxDist.first;
}