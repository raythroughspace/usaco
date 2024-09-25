#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<vector<ssize_t>> painting(1002, vector<ssize_t>(1002));
    for (size_t i=0; i<N; ++i){
        size_t a,b,c,d; cin >> a >> b >> c >>d;
        ++painting[a][b];
        --painting[a][d];
        ++painting[c][d];
        --painting[c][b];
    }
    for (size_t i=0; i<1001; ++i){
        for (size_t j=1; j<1001; ++j){
            painting[i][j] += painting[i][j-1];
        }
    }
    for (size_t j=0; j<1001; ++j){
        for (size_t i=1; i<1001; ++i){
            painting[i][j] += painting[i-1][j];
        }
    }
    size_t ans = 0;
    for (size_t i=0; i<1001; ++i){
        for (size_t j=0; j<1001; ++j){
            if (painting[i][j] == K){
                ++ans;
            }
        }
    }
    cout << ans;
}