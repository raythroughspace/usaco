#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX

int main(){
    cin.tie(0)->sync_with_stdio(0);
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,M; cin >> N >> M;
        vector<size_t> a(N+1);
        vector<size_t> b(M+1);
        vector<size_t> apref(N+1);
        for (size_t i=1; i<=N; ++i){
            cin >> a[i];
            apref[i] = apref[i-1] + a[i];
        }
        for (size_t i=1; i<=M; ++i){
            cin >> b[i];
        }
        vector<vector<size_t>> dp(N+2, vector<size_t>(M+1, INF));
        for (size_t j=M; j>=1; --j){
            dp[N+1][j] = 0; //dp[N+1][j] is empty array
        }

        for (size_t i=N; i>=1; --i){
            size_t hi = i;
            for (size_t j=M; j>=1; --j){
                if (j<M){
                    dp[i][j] = dp[i][j+1];
                }
                if (b[j] >= a[i]){
                    //how much of prefix starting a[i] can b[j] bite off
                    while (hi +1 <=N && apref[hi+1] - apref[i-1] <= b[j]){
                        ++hi;
                    }
                    // bite off up to and including hi
                    dp[i][j] = min(dp[i][j], dp[hi+1][j] + M-j);
                }
            }
        }
        if (dp[1][1] == INF){
            cout << "-1\n";
        }
        else{
            cout << dp[1][1] << "\n";
        }
    }
}