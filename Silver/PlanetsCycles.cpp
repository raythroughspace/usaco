#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, const vector<size_t>& adj, vector<bool>& visited, 
    vector<size_t>& ans, stack<size_t>& path){
    visited[i] = true;
    path.push(i);
    size_t next = adj[i];
    if (visited[next] && !ans[next]){
        // next node ends cycle
        vector<size_t> cycle;
        while (path.top() != next){
            cycle.push_back(path.top());
            path.pop();
        }
        cycle.push_back(path.top());
        path.pop();
        for (auto node: cycle){
            ans[node] = cycle.size();
        }
        return;
    }
    if (!visited[next]){
        dfs(next, adj, visited, ans, path);
    }
    // next node is visited and has answer
    if (!ans[i]){
        ans[i] = ans[next] + 1;
    }
}


int main(){
    size_t N; cin >> N;
    vector<size_t> adj(N+1);
    for (size_t i=1; i<=N; ++i){
        cin >> adj[i];
    }
    vector<size_t> ans(N+1);
    vector<bool> visited(N+1);
    for (size_t i=1; i<=N; ++i){
        stack<size_t> path;
        if (!visited[i]){
            dfs(i, adj, visited, ans, path);
        }
    }

    for (size_t i=1; i<=N; ++i){
        cout << ans[i] << " ";
    }
}