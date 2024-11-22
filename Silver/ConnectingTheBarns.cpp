#include <bits/stdc++.h>
using namespace std;

void dfs(const size_t i, vector<bool>& visited, 
const vector<vector<size_t>>& adj, vector<size_t>& component){
    if (visited[i]){
        return;
    }
    visited[i] = true;
    component.push_back(i);
    for (const auto& j: adj[i]){
        dfs(j, visited, adj, component);
    }
}
// c2 must be sorted
size_t componentsDist(const vector<size_t>& c2, const vector<size_t>& c1){
    size_t minDist = SIZE_MAX;
    for (const auto& i: c1){
        auto lo = lower_bound(c2.begin(), c2.end(), i);
        if (lo == c2.end()){
            //all elements in c2 are less than i 
            --lo;
            minDist = min(minDist, (i - *lo)*(i - *lo));
        }
        else{
            // lo is first element greater than i
            minDist = min(minDist, (*lo - i)*(*lo - i));
            if (lo != c2.begin()){
                --lo;
                minDist = min(minDist, (i - *lo)*(i - *lo));
            }
        }
    }
    return minDist;
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,M; cin >> N >> M;
        vector<vector<size_t>> adj(N+1);
        for (size_t i=0; i<M; ++i){
            size_t a,b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visited(N+1);
        vector<vector<size_t>> components;
        for (size_t i=1; i<=N; ++i){
            vector<size_t> component;
            dfs(i, visited, adj, component);
            if (!component.empty()){
                components.push_back(component);
            }
        }
        size_t idx1,idxN;
        for (size_t i=0; i<components.size(); ++i){
            for (const auto& j: components[i]){
                if (j == 1){
                    idx1 = i;
                }
                if (j == N){
                    idxN = i;
                }
            }
        }
        sort(components[idx1].begin(), components[idx1].end());
        sort(components[idxN].begin(), components[idxN].end());
        if (idx1 == idxN){
            cout << "0\n";
            continue;
        }
        size_t minCost = componentsDist(components[idx1], components[idxN]);
        for (size_t i=0; i<components.size(); ++i){
            if (i == idx1 || i == idxN){
                continue;
            }
            // use ith component as middle step
            minCost = min(minCost, componentsDist(components[idx1], components[i]) + 
            componentsDist(components[idxN], components[i]));
        }
        cout << minCost << "\n";
    }
}