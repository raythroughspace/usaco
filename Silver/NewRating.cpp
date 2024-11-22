#include <bits/stdc++.h>
using namespace std;
ssize_t f(ssize_t a, ssize_t x){
    return a + (a<x) -(a>x);
}
int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<size_t> a(N);
        for (size_t i=0; i<N; ++i){
            cin >> a[i];
        }
        vector<vector<ssize_t>> dp(N, vector<ssize_t>(3));
        dp[0][0] = 1; dp[0][1] = 0; dp[0][2] = -N;
        for (size_t i=1; i<N; ++i){
            dp[i][0] = f(dp[i-1][0], a[i]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = max(f(dp[i-1][1], a[i]), f(dp[i-1][2], a[i]));
        }
        cout << max(dp[N-1][1], dp[N-1][2]) << "\n";
    }
}