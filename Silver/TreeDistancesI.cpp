#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, const vector<vector<size_t>>& adj, vector<size_t>& distance){
    for (const auto& v: adj[i]){
        if (distance[v] == SIZE_MAX){
            distance[v] = distance[i] + 1;
            dfs(v, adj, distance);
        }
    }
}

int main(){
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=1; i<N; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (N==1){
        cout << 0;
        return 0;
    }
    vector<size_t> distance(N+1, SIZE_MAX); 
    distance[1] = 0;
    dfs(1, adj, distance);
    size_t maxDis = 0;
    size_t endpoint1 = 0;
    for (size_t i=1; i<=N; ++i){
        if (maxDis < distance[i]){
            maxDis = distance[i];
            endpoint1 = i;
        }
    }
    fill(distance.begin(), distance.end(), SIZE_MAX);
    distance[endpoint1] = 0;
    dfs(endpoint1, adj, distance);
    maxDis = 0;
    size_t endpoint2 = 0;
    for (size_t i=1; i<=N; ++i){
        if (maxDis < distance[i]){
            maxDis = distance[i];
            endpoint2 = i;
        }
    }
    //distance has all dist from endpoint 1
    vector<size_t> distance2(N+1, SIZE_MAX);
    distance2[endpoint2] = 0;
    dfs(endpoint2, adj, distance2);
    //distance 2 has all dist from endpoint 2
    for (size_t i=1; i<=N; ++i){
        cout << max(distance[i], distance2[i]) << " ";
    }
}