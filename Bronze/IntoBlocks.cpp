#include <bits/stdc++.h>
using namespace std;

// vector a
// map[ai] = {lowestidx, highestidx}
// map[ai] = count number of incidences
// 
int main(){
    size_t n,q; cin >> n >> q;
    vector<size_t> a(n);
    map<size_t,pair<size_t,size_t>> aidx;
    map<size_t, size_t> counts;
    for (size_t i=0; i<n; ++i){
        cin >> a[i];
        ++counts[a[i]];
        aidx[a[i]].first = min(i, aidx[a[i]].first);
        aidx[a[i]].second = max(i, aidx[a[i]].second);
    }
    size_t first = 0;
    size_t last = 0;
    size_t ans = 0;
    size_t max_count = 0;
    for (size_t i=0; i<n; ++i){
        last = max(last, aidx[a[i]].second);
        max_count = max(max_count, counts[a[i]]);
        if (last == i){ // reached end of block
            ans += last - first + 1 - max_count;
            max_count = 0;
            first = last + 1;
        }
    }
    cout << ans;
}