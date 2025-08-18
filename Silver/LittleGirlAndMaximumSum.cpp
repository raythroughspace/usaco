#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,Q; cin >> N >> Q;
    vector<size_t> a(N);
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    vector<ssize_t> pref(N+1);
    for (size_t i=0; i<Q; ++i){
        size_t l,r; cin >> l >> r;
        ++pref[l-1];
        --pref[r];
    }
    for (size_t i=1; i<N; ++i){
        pref[i] += pref[i-1];
    }
    sort(a.rbegin(), a.rend());
    sort(pref.rbegin(), pref.rend());
    size_t max_sum = 0;
    for (size_t i=0; i<N; ++i){
        max_sum += a[i]*pref[i];
    }
    cout << max_sum;
}