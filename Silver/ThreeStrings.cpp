#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        string a,b,c; cin >> a >> b >> c;
        vector<vector<size_t>> dp(a.size()+1, vector<size_t>(b.size()+1, SIZE_MAX));
        dp[0][0] = 0;
        for (size_t i=0; i<= a.size(); ++i){
            for (size_t j=0; j<= b.size(); ++j){
                if (i == 0 && j== 0)
                    continue;
                if (i > 0)
                    dp[i][j] = dp[i-1][j] + !(a[i-1] == c[i+j-1]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + !(b[j-1] == c[i+j-1]));
            }
        }
        cout << dp[a.size()][b.size()] << "\n";
    }
}