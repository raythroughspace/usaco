#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<ssize_t> prefix(N+1, 0);
    vector<ssize_t> count(N, 0);
    count[0] = 1;
    ssize_t ans = 0;
    for (size_t i=1; i<=N; ++i){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
        prefix[i] = ((prefix[i] % N) + N) % N;
        ans += count[prefix[i]];
        ++count[prefix[i]];
    }
    cout << ans;
}