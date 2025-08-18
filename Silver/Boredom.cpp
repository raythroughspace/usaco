#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    map<size_t,size_t> a;
    for (size_t i=0; i<N; ++i){
        size_t ai; cin >> ai;
        ++a[ai];
    }
    vector<size_t> dp(1e5+3, 0); // dp[i] = max number of points picking only elements >=i
    for (ssize_t i=1e5; i>=0; --i){
        dp[i] = max(dp[i+1], dp[i+2] + i*a[i]);
    }
    cout << dp[0];
}