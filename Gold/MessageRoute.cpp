#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M; cin >> N >> M;
    vector<vector<size_t>> adj(N+1);
    vector<size_t> distance(N+1, SIZE_MAX);
    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<size_t> parents(N+1);
    distance[1] = 1;
    queue<size_t> process; process.push(1);
    while (!process.empty()){
        size_t next = process.front();
        process.pop();
        for (const auto &v: adj[next]){
            if (distance[v] == SIZE_MAX){
                process.push(v);
                distance[v] = distance[next] + 1;
                parents[v] = next;
            }
        }
    }
    if (distance[N] == SIZE_MAX){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << distance[N] << "\n";
        stack<size_t> route;
        size_t curr = N;
        while (curr != 1){
            route.push(curr);
            curr = parents[curr];
        }
        route.push(curr);
        while (!route.empty()){
            cout << route.top() << " ";
            route.pop();
        }
    }
}