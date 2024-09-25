#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<ssize_t> prefix(N+1);
    ssize_t min_val = 0;
    ssize_t ans = -LONG_LONG_MAX;
    for (size_t i=1; i<=N; ++i){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
        ans = max(prefix[i] - min_val, ans);
        min_val = min(prefix[i], min_val);
    }
    cout << ans;
}