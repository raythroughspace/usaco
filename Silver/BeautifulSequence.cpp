#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<size_t> a(N+1);
        for (size_t i=0; i<N; ++i){
            cin >> a[i+1];
        }
        vector<vector<size_t>> dp(N+1, vector<size_t>(4));
        for (size_t i=1; i<=N; ++i){
            for (size_t j=1; j<=3; ++j){
                dp[i][j] = (dp[i-1][j] % 998244353);
            }
            if (a[i] == 3){
                dp[i][3] += dp[i-1][2];
            } else if (a[i] == 2){
                dp[i][2] += dp[i-1][2] + dp[i-1][1];
            } else {
                dp[i][1] += 1;
            }
        }
        cout << dp[N][3] % 998244353 << "\n";
    }
}