#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M; cin >> N >> M;
    vector<vector<pair<size_t,size_t>>> adj(2*(N+1));
    for (size_t i=0; i<M; ++i){
        size_t a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[a+N].push_back({b+N, c});
        adj[a].push_back({b+N, c/2});
    }
    vector<size_t> distance(2*(N+1), LONG_LONG_MAX);
    vector<bool> processed(2*(N+1));
    priority_queue<pair<size_t, size_t>, 
    vector<pair<size_t,size_t>>, greater<pair<size_t,size_t>>> pq;
    distance[1] = 0;
    pq.push({distance[1], 1});
    while (!pq.empty()){
        size_t node = pq.top().second;
        pq.pop();
        if (processed[node]){
            continue;
        }
        processed[node] = true;
        for (auto neighbour: adj[node]){
            if (distance[node] + neighbour.second < distance[neighbour.first]){
                distance[neighbour.first] = distance[node] + neighbour.second;
                pq.push({distance[neighbour.first], neighbour.first});
            }
        }
    }
    cout << distance[2*N];
}