#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<size_t> A(N);
    for (size_t i=0; i<N; ++i){
        cin >> A[i];
    }
    vector<size_t> prefix(N); prefix[0] = A[0];
    vector<size_t> suffix(N); suffix[N-1] = A[N-1];
    for (size_t i=1; i<N; ++i){
        prefix[i] = gcd(prefix[i-1], A[i]);
    }
    for (ssize_t i=N-2; i>=0; --i){
        suffix[i] = gcd(suffix[i+1], A[i]);
    }
    size_t ans = max(suffix[1], prefix[N-2]);
    for (size_t i=1; i<N-1; ++i){
        ans = max(ans, gcd(prefix[i-1], suffix[i+1]));
    }
    cout << ans;
}