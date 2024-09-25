#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M; cin >> N >> M;
    vector<string> grid(N);
    for (size_t i=0; i<N; ++i){
        cin >> grid[i];
    }
    size_t ans = 0;
    set<pair<pair<size_t, size_t>,pair<size_t,size_t>>> met; //pairs of cows that already met
    for (ssize_t i=0; i<N; ++i){
        for (ssize_t j=0; j<M; ++j){
            if (grid[i][j] != 'G'){
                continue;
            }
            //(i,j) contains grass
            size_t ncows = 0;
            vector<pair<size_t,size_t>> cows;
            if (i-1 >=0 && grid[i-1][j] == 'C'){
                ++ncows;
                cows.push_back({i-1, j});
            }
            if (i+1 < N && grid[i+1][j] == 'C'){
                ++ncows;
                cows.push_back({i+1, j});
            }
            if (j-1 >=0 && grid[i][j-1] == 'C'){
                ++ncows;
                cows.push_back({i, j-1});
            }
            if (j+1 < M && grid[i][j+1] == 'C'){
                ++ncows;
                cows.push_back({i, j+1});
            }
            if (ncows >= 3){
                ++ans;
            }
            else if (ncows == 2){
                if (!(met.count({cows[0], cows[1]}) || met.count({cows[1], cows[0]}))){
                    // didn't meet already
                    ++ans;
                    met.insert({cows[0], cows[1]});
                }
            }
        }
    }
    cout << ans;
}