#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M; cin >> N >> M;
    vector<vector<pair<size_t,char>>> adj(N+1);
    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a >> b;
        char c; cin >> c;
        if (a != b){
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        else{
            adj[a].push_back({a,c});
        }
    }
    vector<vector<size_t>> distances(N+1, vector<size_t>(N+1, SSIZE_MAX));
    distances[1][N] = 0; //
    queue<pair<size_t,size_t>> toProcess; toProcess.push({1,N});
    while (!toProcess.empty()){
        auto [i,j] = toProcess.front();
        toProcess.pop();
        for (const auto& [a, c1]: adj[i]){
            for (const auto& [b, c2]: adj[j]){
                if (c1 != c2 || distances[a][b] != SSIZE_MAX) continue;
                distances[a][b] = distances[i][j] + 1;
                toProcess.push({a,b});
            }
        }
    }

    size_t best = SSIZE_MAX;
    for (size_t i=1; i<=N; ++i){
        best = min(best, 2*distances[i][i]);
    }
    for (size_t i=1; i<=N; ++i){
        for (const auto& [j, c]: adj[i]){
            best = min(best, 2*distances[i][j] + 1);
        }
    }
    if (best == SSIZE_MAX){
        cout << -1;
    }
    else{
        cout << best;
    }

}