#include <bits/stdc++.h>
using namespace std;

int main(){
    ssize_t N, X; cin >> N >> X;
    vector<ssize_t> prefix(N+1, 0);
    map<ssize_t, size_t> prefix2count;
    ++prefix2count[0];
    size_t ans = 0;
    for (size_t i=1; i<=N; ++i){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
        ans += prefix2count[prefix[i] - X];
        ++prefix2count[prefix[i]];
    }
    cout << ans;
}