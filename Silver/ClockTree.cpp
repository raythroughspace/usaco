//SOLVED
#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, vector<size_t>& visited, const vector<vector<size_t>>& adj, size_t color){
    if (visited[i])
        return;
    
    visited[i] = color;
    color = color == 1 ? 2: 1;
    for (const auto& n: adj[i]){
        dfs(n, visited, adj, color);
    }
}

int main(){
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    vector<size_t> clocks(N+1);
    for (size_t i=1; i<=N; ++i){
        cin >> clocks[i];
    }
    for (size_t i=0; i<N-1; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<size_t> visited(N+1);
    dfs(1, visited, adj, 1);
    vector<size_t> sums(3);
    vector<size_t> nums(3);
    for (size_t i=1; i<=N; ++i){
        sums[visited[i]] += clocks[i];
        ++nums[visited[i]];
    }
    sums[1] %= 12;
    sums[2] %= 12;
    if (sums[1] == sums[2]){
        cout << N;
    }
    else if (sums[1] == (sums[2] + 1)%12){
        cout << nums[1];
    }
    else if (sums[2] == (sums[1] + 1)%12){
        cout << nums[2];
    }
    else{
        cout << 0;
    }
}