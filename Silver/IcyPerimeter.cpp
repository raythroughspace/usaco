#include <bits/stdc++.h>
using namespace std;
void flood_fill(ssize_t i, ssize_t j, vector<vector<char>>& grid, vector<vector<bool>>& visited, size_t &area, 
ssize_t &perimeter){
    ++area;
    perimeter += 4;
    visited[i][j] = true;
    if (i-1 >= 0 && grid[i-1][j] == '#'){
        --perimeter;
        if (!visited[i-1][j]){
            flood_fill(i-1, j, grid, visited, area, perimeter);
        }
    }
    if (i+1 < grid.size() && grid[i+1][j] == '#'){
        --perimeter;
        if (!visited[i+1][j]){
            flood_fill(i+1, j, grid, visited, area, perimeter);
        }
    }
    if (j-1 >=0 && grid[i][j-1] == '#'){
        --perimeter;
        if (!visited[i][j-1]){
            flood_fill(i, j-1, grid, visited, area, perimeter);
        }
    }
    if (j+1 < grid.size() && grid[i][j+1] == '#'){
        --perimeter;
        if (!visited[i][j+1]){
            flood_fill(i, j+1, grid, visited, area, perimeter);
        }
    }
}
int main(){
    //freopen("perimeter.in", "r", stdin);
    //freopen("perimeter.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(N));
    size_t maxArea = 0;
    ssize_t maxPerimeter = 0;
    for (ssize_t i=0; i<N; ++i){
        for (ssize_t j=0; j<N; ++j){
            size_t area = 0;
            ssize_t perimeter = 0;
            if (!visited[i][j] && grid[i][j] == '#'){
                flood_fill(i, j, grid, visited, area, perimeter);
            }
            if (area > maxArea){
                maxArea = area;
                maxPerimeter = perimeter;
            }
            else if (area == maxArea){
                maxPerimeter = max(maxPerimeter, perimeter);
            }
        }
    }
    cout << maxArea << " " << maxPerimeter;

}