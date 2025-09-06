#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    size_t N,G; cin >> N >> G;
	vector<pair<size_t, pair<size_t, ssize_t>>> logEntries;
    for (size_t i=0; i<N; ++i){
        ssize_t a,b,c; cin >> a >> b >> c;
        logEntries.push_back({a,{b,c}});
    }
    sort(logEntries.begin(), logEntries.end());
    map<size_t,size_t> values;  values[G] = 1e9;
    map<size_t,size_t> cow2val;
    size_t ans = 0;
    for (const auto& [a,d]: logEntries){
        auto [b,c] = d;
        if (!cow2val.count(b)){
            cow2val[b] = G;
        }
        bool incr = false;
        bool isTop = false;
        if (cow2val[b] == values.rbegin()->first){
            // cow is top
            isTop = true; 
        }
        --values[cow2val[b]];
        if (!values[cow2val[b]])
            values.erase(cow2val[b]);
        cow2val[b] += c;
        ++values[cow2val[b]];
        if (isTop && cow2val[b] == values.rbegin()->first 
        && c < 0 && values[cow2val[b]] > 1)
            incr = true;
        if (isTop && cow2val[b] < values.rbegin()->first)
            incr = true;
        if (isTop && values.count(cow2val[b] - c))
            incr = true;
        if (!isTop && cow2val[b] == values.rbegin()->first)
            incr = true;
        if (incr)
            ++ans;
    }
    cout << ans;
}