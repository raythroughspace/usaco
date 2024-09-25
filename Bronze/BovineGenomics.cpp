#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    vector<string> spotty;
    vector<string> plain;
    for (size_t i=0; i<N; ++i){
        string cow; cin >> cow;
        spotty.push_back(cow);
    }
    for (size_t i=0; i<N; ++i){
        string cow; cin >> cow;
        plain.push_back(cow);
    }
    size_t ans = 0;
    for (size_t i=0; i<M; ++i){
        for (size_t j=i+1; j<M; ++j){
            for (size_t k=j+1; k<M; ++k){
                bool explain = true;
                unordered_set<string> spotty_pat;
                for (size_t n=0; n<N; ++n){
                    spotty_pat.insert(spotty[n].substr(i,1) + spotty[n].substr(j,1) + spotty[n].substr(k,1));
                }
                for (size_t n=0; n<N; ++n){
                    if (spotty_pat.count(plain[n].substr(i,1) + plain[n].substr(j,1) + plain[n].substr(k,1))){
                        explain = false;
                    }
                }
                if (explain){
                    ++ans;
                }
            }
        }
    }
    cout << ans;
}