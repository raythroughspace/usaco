#include <bits/stdc++.h>
using namespace std;

void flood_fill(size_t x, size_t y, size_t i, size_t j, size_t n, size_t m, 
vector<vector<char>>& grid, vector<vector<bool>>& visited, char color){
    if (x < i || x > j || y < n || y > m || visited[x][y] || grid[x][y] != color){
        return; //invalid bounds or visited already or incorrect color
    }
    visited[x][y] = true;
    flood_fill(x-1, y, i, j, n, m, grid, visited, color);
    flood_fill(x+1, y, i, j, n, m, grid, visited, color);
    flood_fill(x, y-1, i, j, n, m, grid, visited, color);
    flood_fill(x, y+1, i, j, n, m, grid, visited, color);
}

bool is_PCL(size_t N, size_t i, size_t j, size_t n, size_t m, vector<vector<char>>& grid){
    vector<size_t> components(26); 
    vector<vector<bool>> visited(N, vector<bool>(N));
    for (size_t x=i; x<=j; ++x){
        for (size_t y=n; y<=m; ++y){
            if (!visited[x][y]){
                flood_fill(x,y, i,j,n,m,grid,visited, grid[x][y]);
                ++components[grid[x][y] - 'A'];
            }
        }
    }
    size_t ones = 0;
    size_t twoOrMore = 0;
    for (auto e: components){
        if (e == 1){
            ++ones;
        }
        else if (e >= 2){
            ++twoOrMore;
        }
    }
    if (ones == 1 && twoOrMore == 1){
        return true;
    }
    return false;

}
int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            cin >> grid[i][j];
        }
    }
    size_t ans = 0;
    vector<pair<size_t,size_t>> xRange;
    vector<pair<size_t,size_t>> yRange;
    for (size_t i=0; i<N; ++i){
        for (size_t j=i; j<N; ++j){
            for (size_t n=0; n<N; ++n){
                for (size_t m=n; m<N; ++m){
                    if (is_PCL(N, i, j, n, m, grid)){
                        xRange.push_back({i,j});
                        yRange.push_back({n,m});
                    }
                }
            }
        }
    }
    for (size_t i=0; i<xRange.size(); ++i){
        bool PCL = true;
        for (size_t j=0; j<xRange.size(); ++j){
            if (i==j){
                continue;
            }
            if (xRange[j].first <= xRange[i].first && xRange[j].second >= xRange[i].second
            && yRange[j].first <= yRange[i].first && yRange[j].second >= yRange[i].second){
                PCL = false;
            }
        }
        if (PCL){
            ++ans;
        }
    }
    cout << ans;
}