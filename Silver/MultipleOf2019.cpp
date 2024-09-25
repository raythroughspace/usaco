#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    map<size_t, size_t> rem2count;
    rem2count[0] = 1;
    ssize_t val = 0;
    size_t multi = 1;
    size_t ans = 0;
    for (ssize_t i= S.size()-1; i>=0; --i){
        val += (S[i] - '0')*multi;
        multi = (multi * 10) % 2019;
        val = ((val%2019) + 2019) % 2019;
        ans += rem2count[val];
        ++rem2count[val];
    }
    cout << ans;
}