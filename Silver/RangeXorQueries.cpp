#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,Q; cin >> N >> Q;
    vector<size_t> pref(N+1);
    for (size_t i=1; i<=N; ++i){
        cin >> pref[i];
        pref[i] ^= pref[i-1];
    }
    for (size_t q = 0; q<Q; ++q){
        size_t a,b; cin >> a >> b;
        cout << (pref[b] ^ pref[a-1]) << "\n";
    }
}