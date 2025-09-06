#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<N-1; ++i){
        size_t x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<size_t> a(N);
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    vector<bool> visited(N+1); visited[1] = true;
    queue<size_t> toProcess; toProcess.push(1);
    string ans = "YES";
    if (a[0] != 1){
        ans = "NO";
    }
    size_t curr = 1;
    while (!toProcess.empty()){
        size_t node = toProcess.front();
        toProcess.pop();
        unordered_set<size_t> currDistanceNodes;
        for (const auto& neighbour: adj[node]){
            if (visited[neighbour])
                continue;
            currDistanceNodes.insert(neighbour);
            visited[neighbour] = true;
        }
        for (size_t i=0; i< currDistanceNodes.size(); ++i){
            if (!currDistanceNodes.count(a[curr])){
                ans = "NO";
            }
            toProcess.push(a[curr]);
            ++curr;
        }
    }
    cout << ans;
}