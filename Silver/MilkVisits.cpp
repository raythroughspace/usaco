#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, const vector<vector<size_t>>& adj, vector<size_t>& visited, size_t component){
    if (visited[i])
        return;
    visited[i] = component;
    for (const auto& v: adj[i]){
        dfs(v, adj, visited, component);
    }
}

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    string breed; cin >> breed;
    vector<vector<size_t>> adj(N);
    for (size_t i=0; i<N-1; ++i){
        size_t a,b; cin >> a >> b;
        --a; --b;
        if (breed[a] == breed[b]){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    vector<pair<size_t,size_t>> AB(M);
    vector<char> C(M);
    for (size_t i=0; i<M; ++i){
        cin >> AB[i].first >> AB[i].second >> C[i];
        --AB[i].first;
        --AB[i].second;
    }
    vector<size_t> visited(N);
    size_t component = 1;
    for (size_t i=0; i<N; ++i){
        if (!visited[i]){
            dfs(i, adj, visited, component);
            ++component;
        }
    }
    for (size_t i=0; i<M; ++i){
        if (visited[AB[i].first] == visited[AB[i].second] && C[i] != breed[AB[i].first]){
            cout << 0;
        }
        else{
            cout << 1;
        }
    }
}