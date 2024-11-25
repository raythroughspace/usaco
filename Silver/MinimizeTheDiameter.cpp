#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, size_t N, const vector<vector<size_t>>& adj, vector<size_t>& distance){
    for (const auto& v: adj[i]){
        if (distance[v] == SIZE_MAX){
            distance[v] = distance[i] + 1;
            dfs(v, N, adj, distance);
        }
    }
}

size_t diameter(size_t N, const vector<vector<size_t>>& adj){
    vector<size_t> distance(N+1, SIZE_MAX);
    distance[1] = 0;
    dfs(1, N, adj, distance);
    size_t farthest = 0;
    size_t endpoint = 0;
    for (size_t i=1; i<=N; ++i){
        if (farthest < distance[i]){
            endpoint = i;
            farthest = distance[i];
        }
    }
    vector<size_t> distance2(N+1, SIZE_MAX);
    distance2[endpoint] = 0;
    dfs(endpoint, N, adj, distance2);
    farthest = 0;
    for (size_t i=1; i<=N; ++i){
        if (farthest < distance2[i])
            farthest = distance2[i];
    }
    return farthest;
}

int main(){
    size_t N; cin >> N;
    vector<vector<size_t>> adj1(N+1);
    for (size_t i=1; i<N; ++i){
        size_t a,b; cin >> a >> b;
        adj1[a].push_back(b);
        adj1[b].push_back(a);
    }
    size_t M; cin >> M;
    vector<vector<size_t>> adj2(M+1);
    for (size_t i=1; i<M; ++i){
        size_t a,b; cin >> a >> b;
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }
    cout <<  max<size_t>(1 + (diameter(N, adj1)+1)/2 + (diameter(M, adj2)+1)/2, 
                            max(diameter(N, adj1), diameter(M, adj2)));
}