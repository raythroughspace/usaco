#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<size_t,size_t>> points(N+2);
    map<size_t, vector<size_t>> horizontal;
    map<size_t, vector<size_t>> vertical;
    for (size_t i=0; i<N+2; ++i){
        cin >> points[i].first >> points[i].second;
        vertical[points[i].first].push_back(i);
        horizontal[points[i].second].push_back(i);
    }

    vector<size_t> dist(N+2, SSIZE_MAX);
    queue<pair<size_t, bool>> toProcess;
    toProcess.push({0, true}); // horizontal
    toProcess.push({0, false}); //vertical
    dist[0] = 0;
    while (!toProcess.empty()){
        auto [i, dir] = toProcess.front();
        toProcess.pop();
        if (dir){
            // horizontal laser
            for (const auto& v: horizontal[points[i].second]){
                if (v==i){
                    continue;
                }
                if (dist[v] > dist[i] + 1){
                    dist[v] = dist[i] + 1;
                    toProcess.push({v, false});
                }
            }
        }
        else{
            for (const auto& v: vertical[points[i].first]){
                if (v==i){
                    continue;
                }
                if (dist[v] > dist[i] + 1){
                    dist[v] = dist[i] + 1;
                    toProcess.push({v, true});
                }
            }
        }
    }
    if (dist[1] == SSIZE_MAX){
        cout << -1;
    }
    else{
        cout << dist[1] - 1;
    }
}