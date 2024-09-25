#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> prefixes(N+1,0);
    cin >> prefixes[1];
    for (size_t i=1; i<N; ++i){
        cin >> prefixes[i+1];
        prefixes[i+1] += prefixes[i];
    }
    ssize_t ans = 0;
    for (ssize_t i=0; i<7; ++i){
        ssize_t lo = N+1;
        for (ssize_t j=0; j<N+1; ++j){
            if (prefixes[j] % 7 == i){
                lo = j;
                break;
            }
        }
        for (ssize_t j=N; j>=0; --j){
            if (prefixes[j] % 7 == i){
                ans = max(j - lo, ans);
            }
        }
    }
    cout << ans;
}