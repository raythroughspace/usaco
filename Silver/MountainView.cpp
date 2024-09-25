#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<ssize_t,ssize_t>> peaks(N);
    for (size_t i=0; i<N; ++i){
        cin >> peaks[i].first >> peaks[i].second;
    }
    sort(peaks.begin(), peaks.end(), [](pair<ssize_t, ssize_t> x, pair<ssize_t, ssize_t> y) {
        return x.second - x.first < y.second - y.first;
    });
    set<pair<ssize_t,ssize_t>> s;
    for (size_t i=0; i<N; ++i){ // loop in increasing y-x
        s.insert({peaks[i].second - peaks[i].first, peaks[i].first});
        auto it = s.begin();
        while (*it != make_pair(peaks[i].second - peaks[i].first, peaks[i].first)){
            if ((*it).second <= peaks[i].first){ //it is blocked by peak[i]
                it = s.erase(it);
            }
            else{
                ++it;
            }
        }
    }
    sort(peaks.begin(), peaks.end(), [](pair<ssize_t, ssize_t> x, pair<ssize_t, ssize_t> y) {
        return x.second + x.first < y.second + y.first;
    });
    set<pair<ssize_t,ssize_t>> s1;
    for (size_t i=0; i<N; ++i){ // loop in increasing y-x
        s1.insert({peaks[i].second + peaks[i].first, peaks[i].first});
        auto it = s1.begin();
        while (*it != make_pair(peaks[i].second + peaks[i].first, peaks[i].first)){
            if ((*it).second >= peaks[i].first){ //it is blocked by peak[i]
                it = s1.erase(it);
            }
            else{
                ++it;
            }
        }
    }
    size_t ans = 0;
    for (auto e: s){
        if (s1.count({e.first + 2*e.second, e.second})){
            ++ans;
        }
    }
    cout << ans;
}