#include <bits/stdc++.h>
using namespace std;

void n_paths(vector<string>& grid, ssize_t i, ssize_t j, char dir, ssize_t K, ssize_t N, size_t& ans){
    if (i < 0 || i > N-1 || j < 0 || j > N-1 || grid [i][j] == 'H'){
        return; //out of bounds or walked on haybale
    }
    if (i == N-1 && j == N-1){
        ++ans;
        return; // valid path
    }
    if (dir == 'I'){
        n_paths(grid, i+1, j, 'R', K, N, ans);
        n_paths(grid, i, j+1, 'D', K, N, ans);
    }
    else if (dir == 'R'){
        n_paths(grid, i+1, j, dir, K, N, ans);
        if (K > 0){
            n_paths(grid, i, j+1, 'D', K-1, N, ans);
        }
    }
    else{
        n_paths(grid, i, j+1, dir, K, N, ans);
        if (K > 0){
            n_paths(grid, i+1, j, 'R', K-1, N, ans);
        }
    }

}
int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        ssize_t N,K; cin >> N >> K;
        size_t ans = 0;
        vector<string> grid(N);
        for (size_t i=0; i<N; ++i){
            cin >> grid[i];
        }
        n_paths(grid, 0, 0, 'I', K, N, ans);
        cout << ans << "\n";
    }
}