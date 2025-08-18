#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,X; cin >> N >> X;
    vector<pair<ssize_t,size_t>> a(N);
    for (size_t i=0; i<N; ++i){
        size_t ai; cin >> ai;
        a[i] = {ai, i};
    }
    sort(a.begin(), a.end());
    for (size_t i=0; i<N; ++i){
        if (X < a[i].first)
            continue;
        ssize_t target = X - a[i].first;
        size_t lo = 0;
        size_t hi = N-1;
        while (lo < hi){
            if (lo == i){
                ++lo;
                continue;
            }
            if (hi == i){
                --hi;
                continue;
            }
            if (a[lo].first + a[hi].first > target){
                --hi;
            } else if (a[lo].first + a[hi].first < target){
                ++lo;
            } else {
                cout << a[i].second + 1 << " " << a[lo].second + 1 << " " << a[hi].second + 1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}