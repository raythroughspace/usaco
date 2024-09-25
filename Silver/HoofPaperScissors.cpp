#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    // 0 = HOOF, 1 = PAPER, 2 = SCISSORS
    size_t N; cin >> N;
    vector<vector<size_t>> prefix(3, vector<size_t>(N+1));
    for (size_t i=0; i<N; ++i){
        char in; cin >> in;
        if (in == 'H'){
            ++prefix[0][i+1];
        }
        else if (in == 'P'){
            ++prefix[1][i+1];
        }
        else{
            ++prefix[2][i+1];
        }
        for (size_t j=0; j<3; ++j){
            prefix[j][i+1] += prefix[j][i];
        }
    }
    size_t score = 0;
    for (size_t i=0; i<3; ++i){
        for (size_t j=0; j<3; ++j){
            if (i==j){
                continue;
            }
            for (size_t x=1; x<N+1; ++x){
                score = max(score, prefix[i][x] + prefix[j][N] - prefix[j][x]);
            }
        }
    }
    cout << score;
}