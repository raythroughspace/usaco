#include <bits/stdc++.h>
using namespace std;

void dfs(size_t node, const vector<vector<size_t>>& adj, 
    vector<bool>& visited, bool color){
        visited[node] = true;
        for (const auto& v: adj[node]){
            if (visited[v])
                continue;
            if (color){ // color = 1, all edges go outwards
                cout << node << " " << v << "\n";
            } else {
                cout << v << " " << node << "\n";
            }
            dfs(v, adj, visited, !color);
        }
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<vector<size_t>> adj(N+1);
        for (size_t i=0; i<N-1; ++i){
            size_t a,b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ssize_t deg2 = -1;
        for (size_t i=1; i<=N; ++i){
            if (adj[i].size() == 2){
                deg2 = i;
                break;
            }
        }
        if (deg2 == -1){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << adj[deg2][0] << " " << deg2 << "\n";
        cout << deg2 << " " << adj[deg2][1] << "\n";
        vector<bool> visited(N+1); visited[deg2] = true;
        bool color = true;
        dfs(adj[deg2][0], adj, visited, color);
        color = false;
        dfs(adj[deg2][1], adj, visited, color);
    }
}