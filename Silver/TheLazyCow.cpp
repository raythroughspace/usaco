#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    ssize_t N,K; cin >> N >> K;
    vector<vector<ssize_t>> field(N+1, vector<ssize_t>(N+1, 0));
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=N; ++j){
            cin >> field[i][j];
            field[i][j] += field[i][j-1];
        }
    }
    ssize_t ans = 0;
    for (ssize_t i=1; i<=N; ++i){
        for (ssize_t j=1; j<=N; ++j){
            ssize_t grass = 0;
            for (ssize_t n=K; n>=0; --n){
                ssize_t lo = max((ssize_t)0, i-n-1);
                ssize_t hi = min(N, i+n);
                if (j+K-n>=0 && j+K-n<=N){
                    grass += (field[j+K-n][hi] - field[j+K-n][lo]);
                }
                if (n!= K && j-K+n>=0 && j-K+n<=N){
                    grass += (field[j-K+n][hi] - field[j-K+n][lo]);
                }
            }
            ans = max(ans, grass);
        }
    }
    cout << ans;

}