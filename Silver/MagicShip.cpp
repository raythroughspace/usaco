#include <bits/stdc++.h>
using namespace std;

bool possible(ssize_t days, size_t N, vector<pair<ssize_t,ssize_t>>& pref, 
                ssize_t a, ssize_t b, ssize_t c, ssize_t d){
    size_t p = days/N;
    size_t q = days - p*N;
    a = a + pref[N-1].first*p;
    b = b + pref[N-1].second*p;
    if (q != 0){
        a += pref[q-1].first;
        b += pref[q-1].second;
    }
    return (abs(c-a) + abs(d-b) <= days);
}

int main(){
    ssize_t a,b,c,d; cin >> a >> b >> c >> d;
    size_t N; cin >> N;
    string s; cin >> s;
    vector<pair<ssize_t,ssize_t>> pref(N);
    for (size_t i=0; i<N; ++i){
        if (s[i] == 'U'){
            pref[i] = {0, 1};
        }
        else if (s[i] == 'D'){
            pref[i] = {0, -1};
        }
        else if (s[i] == 'L'){
            pref[i] = {-1, 0};
        }
        else{
            pref[i] = {1, 0};
        }
        if (i != 0){
            pref[i] = {pref[i].first + pref[i-1].first, pref[i].second + pref[i-1].second};
        }
    }
    ssize_t lo = 0;
    ssize_t hi = INT64_MAX/2;
    ssize_t valid = -1;
    while (lo <= hi){
        ssize_t mid = (lo + hi)/2;
        if (possible(mid, N, pref, a, b, c, d)){
            hi = mid - 1;
            valid = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << valid;
}