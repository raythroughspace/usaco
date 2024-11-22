#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, vector<bool>& visited, const vector<vector<size_t>>& adj){
    if (visited[i]){
        return;
    }
    visited[i] = true;
    for (const auto& v: adj[i]){
        dfs(v, visited, adj);
    }
}

int main(){
    size_t N; cin >> N;
    vector<vector<size_t>> pref(N+1, vector<size_t>(N+1));
    vector<vector<size_t>> adj(N+1);
    for (size_t i=1; i<=N; ++i){
        bool encounteredi = false;
        for (size_t j=1; j<=N; ++j){
            cin >> pref[i][j];
            if (pref[i][j] == i){
                encounteredi = true;
            }
            if (!encounteredi){
                adj[i].push_back(pref[i][j]); //i -> pref[i][j]
            }
        }
    } 

    vector<vector<bool>> reachable(N+1, vector<bool>(N+1));
    for (size_t i=1; i<=N; ++i){
        dfs(i, reachable[i], adj);
    }

    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=N; ++j){
            if (reachable[pref[i][j]][i]){
                cout << pref[i][j] << "\n";
                break;
            }
        }
    }
}