#include <bits/stdc++.h>
using namespace std;
void flood_fill(ssize_t i, ssize_t j, size_t D, size_t M, size_t N, 
vector<vector<ssize_t>>& elevations, vector<vector<bool>>& visited){
    if (visited[i][j]){
        return; // already visited
    }
    visited[i][j] = true;
    if (i-1 >=0 && (abs(elevations[i][j] - elevations[i-1][j]) <= D)){
        flood_fill(i-1, j, D, M, N, elevations, visited);
    }
    if (i+1 < M && (abs(elevations[i][j] - elevations[i+1][j]) <= D)){
        flood_fill(i+1, j, D, M, N, elevations, visited);
    }
    if (j-1 >=0 && (abs(elevations[i][j] - elevations[i][j-1]) <= D)){
        flood_fill(i, j-1, D, M, N, elevations, visited);
    }
    if (j+1 < N && (abs(elevations[i][j] - elevations[i][j+1]) <= D)){
        flood_fill(i, j+1, D, M, N, elevations, visited);
    }
}

bool is_connected(size_t D, size_t M, size_t N,
 vector<vector<ssize_t>>& elevations, vector<pair<size_t,size_t>>& waypoints){
    vector<vector<bool>> visited(M, vector<bool>(N));
    //flood fill starting from first waypoint
    flood_fill(waypoints[0].first, waypoints[0].second, D, M, N, elevations, visited);
    for (auto p: waypoints){
        if (!visited[p.first][p.second]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    size_t M,N; cin >> M >> N;
    vector<vector<ssize_t>> elevations(M, vector<ssize_t>(N));
    for (size_t i=0; i<M; ++i){
        for (size_t j=0; j<N; ++j){
            cin >> elevations[i][j];
        }
    }
    vector<pair<size_t, size_t>> waypoints;
    for (size_t i=0; i<M; ++i){
        for (size_t j=0; j<N; ++j){
            size_t a; cin >> a;
            if (a== 1){
                waypoints.push_back({i,j});
            }
        }
    }
    ssize_t lo = 0;
    ssize_t hi = 1e10 + 1;
    size_t ans = 1e10 + 1;
    while (lo < hi){ // lo inclusive, hi exclusive
        size_t mid = (lo + hi)/2;
        if (!is_connected(mid, M, N, elevations, waypoints)){
            // mid is not OK, need to go higher
            lo = mid + 1;
        }
        else{
            //mid is OK try lower or equal
            hi = mid;
            ans = min(ans, mid);
        }
    }
    cout << ans;
}