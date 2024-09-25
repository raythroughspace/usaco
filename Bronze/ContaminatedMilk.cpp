#include <bits/stdc++.h>
using namespace std;
// for each milk m (M)
//      for each person p in last S lines
//          check if m could have made p sick (check that p drank m before t)
//               by looping through D lines to see if p drank m before t
//      if (m could have been bad), 
//          loop through D lines for # of people who drank m
int main(){
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    size_t N,M,D,S; cin >> N >> M >> D >> S;
    vector<tuple<long,long,long>> milk_drink;
    vector<pair<long,long>> sick;
    for (size_t i=0; i< D; ++i){
        long a,b,c; cin >> a >> b >> c;
        milk_drink.push_back({a,b,c});
    }
    for (size_t i=0; i<S; ++i){
        long a,b; cin >> a >> b;
        sick.push_back({a,b});
    }
    size_t ans = 0;
    for (size_t m=1; m<=M; ++m){
        bool isbad = true;
        for (auto s: sick){
            bool mbeforet = false;
            for (auto d: milk_drink){
                if (m == get<1>(d) && s.first == get<0>(d) && s.second > get<2>(d)){
                    mbeforet = true;
                }
            }
            if (!mbeforet){
                isbad = false;
            }
        }
        if (isbad){
            unordered_set<long> ndrank;
            for (auto d: milk_drink){
                if (get<1>(d) == m){
                    ndrank.insert(get<0>(d));
                }
            }
            ans = max(ans, ndrank.size());
        }
    }
    cout << ans;
}