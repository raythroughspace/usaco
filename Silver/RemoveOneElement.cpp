#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<size_t> a(N);
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    vector<size_t> pref(N, 1);
    vector<size_t> suff(N, 1);
    for (size_t i=1; i<N; ++i){
        if (a[i] > a[i-1])
            pref[i] = pref[i-1] + 1;
    }
    for (ssize_t i=N-2; i>=0; --i){
        if (a[i] < a[i+1])
            suff[i] = suff[i+1] + 1;
    }
    size_t ans = *max_element(pref.begin(), pref.end());
    for (size_t i=0; i<N-2; ++i){
        if (a[i] < a[i+2])
            ans = max(ans, pref[i] + suff[i+2]);
    }
    cout << ans;
}