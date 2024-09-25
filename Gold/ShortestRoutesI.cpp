#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M; cin >> N >> M;
    vector<vector<pair<size_t,size_t>>> adj(N+1);
    for (size_t i=0; i<M; ++i){
        size_t a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<size_t> distance(N+1, LONG_LONG_MAX);
    priority_queue<pair<size_t, size_t>, 
    vector<pair<size_t, size_t>>, greater<pair<size_t,size_t>>> pq;
    vector<bool> processed(N+1);
    distance[1] = 0;
    pq.push({distance[1], 1});
    while (!pq.empty()){
        size_t node = pq.top().second;
        pq.pop();
        if (processed[node]){
            continue;
        }
        processed[node] = true;
        for (auto neig: adj[node]){
            if (distance[node] + neig.second < distance[neig.first]){
                distance[neig.first] = distance[node] + neig.second;
                pq.push({distance[neig.first], neig.first});
            }
        }
    }
    for (size_t i=1; i<=N; ++i){
        cout << distance[i] << " ";
    }
}