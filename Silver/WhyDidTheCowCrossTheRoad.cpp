#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    size_t C,N; cin >> C >> N;
    multiset<size_t> chickens;
    vector<pair<size_t,size_t>> intervals(N);
    for (size_t i=0; i<C; ++i){
        size_t c; cin >> c;
        chickens.insert(c);
    }
    for (size_t i=0; i<N; ++i){
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), [](const pair<size_t,size_t> a, const pair<size_t,size_t> b){
        return a.second < b.second;
    });
    size_t ans = 0;
    for (size_t i=0; i<N; ++i){ // for each interval, find smallest chicken 
        auto lo = chickens.lower_bound(intervals[i].first);
        if (lo == chickens.end()){
            continue; // interval[i].first > all chickens
        }
        else if (*lo <= intervals[i].second){
            ++ans;
            chickens.erase(lo);
        }
    }
    cout << ans;
}