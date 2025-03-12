#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,K;
    cin >> N >> K;
    vector<ssize_t> pref(N+2);
    for (size_t i=0; i<K; ++i){
        size_t a,b; cin >> a >> b;
        ++pref[a]; --pref[b+1];
    }
    for (size_t i=1; i<=N; ++i){
        pref[i] += pref[i-1];
    }
    pref[0] = pref[N+1] = SSIZE_MAX;
    sort(pref.begin(), pref.end());
    cout << pref[N/2];
}