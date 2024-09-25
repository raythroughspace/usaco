#include <bits/stdc++.h> 
using namespace std;

int main(){
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);
    size_t N,B; cin >> N >> B;
    vector<pair<long,long>> cows;
    vector<long> xsep; vector<long> ysep;
    for (size_t i=0; i<N; ++i){
        long a,b; cin >> a >>b;
        cows.push_back({a,b});
        xsep.push_back(a+1); xsep.push_back(a-1);
        ysep.push_back(b+1); ysep.push_back(b-1);
    }
    size_t ans = 100;
    for (auto x: xsep){
        for (auto y: ysep){
            size_t ul,ur,ll,lr; ul=0; ur=0; ll=0; lr=0;
            for (auto cow: cows){
                if (cow.first > x && cow.second > y){
                    ++ul;
                }
                else if (cow.first > x && cow.second < y){
                    ++ll;
                }
                else if (cow.first < x && cow.second > y){
                    ++ur;
                }
                else{
                    ++lr;
                }
            }
            ans = min(ans, max(ul, max(ur, max(ll,lr))));
        }
    }
    cout << ans;
}