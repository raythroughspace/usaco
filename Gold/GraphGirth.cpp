#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M; cin >> N >> M;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    size_t minCycle = SIZE_MAX;
    for (size_t i=1; i<=N; ++i){
        //cycle starting at i
        vector<size_t> distance(N+1, SIZE_MAX);
        distance[i] = 0;
        queue<size_t> toProcess; toProcess.push(i);
        vector<size_t> parent(N+1);
        while (!toProcess.empty()){
            size_t curr = toProcess.front();
            toProcess.pop();
            for (const auto& v: adj[curr]){
                if (distance[v] == SIZE_MAX){
                    toProcess.push(v);
                    distance[v] = distance[curr] +1;
                    parent[v] = curr;
                }
                else if (parent[curr] != v){
                    // visited v before 
                    minCycle = min(minCycle, distance[curr] + distance[v] + 1);
                }
            }
        }
    }
    if (minCycle == SIZE_MAX){
        cout << -1;
    }
    else{
        cout << minCycle;
    }
}