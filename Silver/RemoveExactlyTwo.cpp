#include <bits/stdc++.h>
using namespace std;
 
int main() {
	size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<vector<size_t>> adj(N);
        for (size_t i=0; i<N-1; ++i){
            size_t u,v; cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        map<size_t,size_t> degrees;
        for (const auto& vertex: adj){
            ++degrees[vertex.size()];
        }
        size_t ans = 0;
        for (size_t i=0; i<N; ++i){
            size_t comp = adj[i].size();
            --degrees[adj[i].size()]; // delete vertex i
            if (degrees[adj[i].size()] == 0)
                degrees.erase(adj[i].size());
            for (const auto& vertex: adj[i]){
                --degrees[adj[vertex].size()];
                if (degrees[adj[vertex].size()] == 0)
                    degrees.erase(adj[vertex].size());
                ++degrees[adj[vertex].size()-1];
            }
            comp += degrees.rbegin()->first;
            for (const auto& vertex: adj[i]){
                --degrees[adj[vertex].size()-1];
                if (degrees[adj[vertex].size() -1] == 0)
                    degrees.erase(adj[vertex].size() - 1);
                ++degrees[adj[vertex].size()];
            }
            ++degrees[adj[i].size()];
            ans = max(comp, ans);
        }
        cout << ans -1 << "\n";
    }
}