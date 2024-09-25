#include <bits/stdc++.h>
using namespace std;

int main(){
    long N,B; cin >> N >> B;
    vector<pair<long,long>> cows;
    map<long, set<long>> y_cows;
    vector<long> xsep; vector<long> ysep;
    for (long i=0; i<N; ++i){
        long a,b; cin >> a >> b;
        cows.push_back({a,b});
        y_cows[b].insert(a);
        xsep.push_back(a-1);
        ysep.push_back(b-1);
    }
    size_t ans = 100;
    for (size_t i=0; i<N; ++i){
        size_t ul,ur,ll,lr; ul=0; ur=0; ll=0; lr=0;
        for (size_t j=0; j<N; ++j){
            long x = xsep[i]; long y = ysep[j];
            if (j==0){
                for (auto cow: cows){
                    if (cow.first < x && cow.second > y){
                        ++ul;
                    }
                    else if (cow.first < x && cow.second < y){
                        ++ll;
                    }
                    else if (cow.first > x && cow.second > y){
                        ++ur;
                    }
                    else{
                        ++lr;
                    }
                }
            }
            else{
                for (auto x_cow: y_cows[ysep[j-1] + 1]){
                    if (x_cow > x){
                        ur--; lr++;
                    }
                    else{
                        ul--; ll++;
                    }
                }
            }
            ans = min(ans, max(ul, max(ur, max(ll,lr))));
        }
    }
    cout << ans;
}