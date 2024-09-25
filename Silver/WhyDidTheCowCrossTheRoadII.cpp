#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    size_t N,K,B; cin >> N >> K >> B;
    vector<size_t> prefix(N+1, 1);
    prefix[0] = 0;
    for (size_t i=0; i<B; ++i){
        size_t idx; cin >> idx;
        prefix[idx] = 0;
    }
    for (size_t i=1; i<=N; ++i){
        prefix[i] += prefix[i-1];
    }
    size_t largest = 0;
    for (size_t i=K; i<=N; ++i){
        largest = max(largest, prefix[i] - prefix[i-K]);
    }
    cout << K-largest;
}