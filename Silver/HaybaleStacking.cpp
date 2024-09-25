#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("stacking.in", "r", stdin);
    //freopen("stacking.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<ssize_t> prefix(N+2, 0);
    for (size_t i=0; i<K; ++i){
        size_t a,b; cin >> a >> b;
        ++prefix[a]; --prefix[b+1];
    }
    for (size_t i=1; i<=N; ++i){
        prefix[i] += prefix[i-1];
    }
    sort(prefix.begin() + 1, prefix.end() -1);
    cout << prefix[(N+1)/2];
}