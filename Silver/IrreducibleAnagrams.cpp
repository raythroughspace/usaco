#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    size_t Q; cin >> Q;
    vector<vector<size_t>> pref(s.size(), vector<size_t>(26));
    ++pref[0][s[0] - 'a'];
    for (size_t i=1; i<s.size(); ++i){
        for (size_t j=0; j<26; ++j){
            pref[i][j] += pref[i-1][j];
        }
        ++pref[i][s[i] - 'a'];
    }
    for (size_t q=0; q<Q; ++q){
        size_t l,r; cin >> l >> r;
        --l; --r;
        string ans = "NO";
        if (l == r || s[l] != s[r]){
            ans = "YES";
        } else {
            size_t distinct = 0;
            for (size_t i=0; i<26; ++i){
                if (l == 0){
                    if (pref[r][i] > 0)
                        ++distinct;
                } else {
                    if (pref[r][i] - pref[l][i] > 0)
                        ++distinct;
                }
            }
            if (distinct >= 3)
                ans = "YES";
        }
        cout << ans << "\n";
    }
}