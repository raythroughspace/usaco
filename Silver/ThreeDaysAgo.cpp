#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    unordered_map<size_t, size_t> count; count[0] = 1;
    size_t pref = 0;
    size_t ans = 0;
    for (size_t i=1; i<=S.size(); ++i){
        pref = pref ^ (1 << (S[i-1] - '0'));
        ans += count[pref];
        ++count[pref];
    }
    cout << ans;
}