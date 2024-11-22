#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ssize_t X,Y,K,M; cin >> X >> Y>> K >> M;
    vector<vector<ssize_t>> distance(X+1, vector<ssize_t>(Y+1, INT_MAX));
    distance[0][0] = 0;
    queue<pair<ssize_t,ssize_t>> toProcess; toProcess.push({0,0});
    while (!toProcess.empty()){
        auto [i,j] = toProcess.front();
        toProcess.pop();
        if (X-i > 0 && distance[X][j] == INT_MAX){
            // fill X to top
            distance[X][j] = distance[i][j] + 1;
            toProcess.push({X,j});
        }
        if (Y-j > 0 && distance[i][Y] == INT_MAX){
            distance[i][Y] = distance[i][j] + 1;
            toProcess.push({i, Y});
        }
        if (i > 0 && distance[0][j] == INT_MAX){
            distance[0][j] = distance[i][j] + 1;
            toProcess.push({0, j});
        }
        if (j > 0 && distance[i][0] == INT_MAX){
            distance[i][0] = distance[i][j] + 1;
            toProcess.push({i, 0});
        }
        //pour i into j
        ssize_t amt = min(i, Y-j);
        if (distance[i-amt][j+amt] == INT_MAX){
            distance[i-amt][j+amt] = distance[i][j] + 1;
            toProcess.push({i-amt, j+amt});
        }
        //pour j into i
        amt = min(X-i, j);
        if (distance[i+amt][j-amt] == INT_MAX){
            distance[i+amt][j-amt] = distance[i][j] + 1;
            toProcess.push({i+amt, j-amt});
        }
    }
    ssize_t best = INT_MAX;
    for (size_t i=0; i<=X; ++i){
        for (size_t j=0; j<=Y; ++j){
            if (distance[i][j] > K){
                continue;
            }
            best = min(best, abs<ssize_t>(M-(i+j)));
        }
    }
    cout << best;
}