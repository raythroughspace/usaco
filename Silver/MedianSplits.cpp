#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,K; cin >> N >> K;
        vector<ssize_t> a(N+1);
        for (size_t i=0; i<N; ++i){
            size_t A;
            cin >> A;
            a[i] = (A <= K) ? 1 : -1;
        }
        vector<ssize_t> pref(N+1);
        vector<ssize_t> pref_max(N+1, -SSIZE_MAX);
        vector<ssize_t> pref_min(N+1, SSIZE_MAX);
        for (size_t i=1; i<=N; ++i){
            pref[i] = pref[i-1] + a[i-1]; // pref[2] -> a[0] + a[1]
            pref_max[i] = max(pref_max[i-1], pref[i]);
            pref_min[i] = min(pref_min[i-1], pref[i]);
        }
        vector<ssize_t> suff(N+1);
        vector<ssize_t> suff_max(N+1, -SSIZE_MAX);
        vector<ssize_t> suff_min(N+1, SSIZE_MAX);
        for (ssize_t i=N-2; i>=0; --i){
            suff[i] = suff[i+1] + a[i+1]; // suff[3] = a[4] + a[5] ...
            suff_max[i] = max(suff_max[i+1], suff[i]);
            suff_min[i] = min(suff_min[i+1], suff[i]);
        }
        string ans = "NO";
        // left is lower than K
        for (size_t i=1; i<N-1; ++i){
            // try l = 1, 2, .. N-2
            if (pref[i] >= 0){
                if (suff_max[i-1] >= 0) // can find a right segment >= 0
                    ans = "YES";
                if (suff[i-1] - suff_min[i] >=0) // can find a mid segment >= 0
                    ans = "YES";
            }
        }

        for (ssize_t i=N-2; i>=1; --i){
            // try r = N-1 .... 0
            if (suff[i] >= 0){
                if (pref_max[i+1] >= 0)
                    ans = "YES";
                if (pref[i+1] - pref_min[i] >=0)
                    ans = "YES";
            }
        }
        cout << ans << "\n";
    }
}