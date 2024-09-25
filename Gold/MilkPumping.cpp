#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    // for each flow rate, set it as minimum allowed. 
    // then calculate min cost possible in resulting graph
    size_t N,M; cin >> N >> M;
    vector<vector<tuple<size_t,size_t,size_t>>> adj(N+1);
    vector<size_t> flows(M);
    for (size_t i=0; i<M; ++i){
        size_t a,b,c,f; cin >> a >> b >> c >> f;
        adj[a].push_back({b,c,f});
        adj[b].push_back({a,c,f});
        flows[i] = f;
    }
    size_t ans = 0;
    for (auto F: flows){
        vector<size_t> cost(N+1, LONG_LONG_MAX);
        vector<bool> processed(N+1);
        priority_queue<pair<size_t,size_t>, 
        vector<pair<size_t,size_t>>, greater<pair<size_t,size_t>>> pq;
        cost[1] = 0;
        pq.push({cost[1], 1});
        while (!pq.empty()){
            size_t node = pq.top().second;
            pq.pop();
            if (processed[node]){
                continue;
            }
            processed[node] = true;
            for (auto neighbour: adj[node]){ //node -> (b,c,f)
                size_t b,c,f; tie(b,c,f) = neighbour; 
                if ((F <= f) && (cost[node] + c < cost[b])){
                    cost[b] = cost[node] + c;
                    pq.push({cost[b], b});
                }
            }
        }
        if (cost[N] != 0){
            ans = max(ans, (F * (size_t)1e6)/cost[N]); // no path from 1 to N using minimum F
        }
    }
    cout << ans;
}