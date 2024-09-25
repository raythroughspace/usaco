#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    set<string> allChars;
    size_t N; cin >> N;
    vector<set<string>> pops(N);
    for (size_t i=0; i<N; ++i){
        size_t K; cin >> K;
        for (size_t j=0; j<K; ++j){
            string c; cin >> c;
            pops[i].insert(c);
            allChars.insert(c);
        }
    }
    bool ans = true;
    for (auto c1: allChars){
        for (auto c2: allChars){
            if (c1 == c2){
                continue;
            }
            vector<bool> crossing(3,false); //01, 10, 11
            for (size_t i=0; i<N; ++i){
                if (pops[i].count(c1) && pops[i].count(c2)){
                    crossing[2] = true;
                }
                else if (pops[i].count(c1)){
                    crossing[0] = true;
                }
                else if (pops[i].count(c2)){
                    crossing[1] = true;
                }
            }
            bool cross = true;
            for (auto c: crossing){
                if (!c){
                    cross = false;
                }
            }
            if (cross){
                ans = false;
            }

        }
    }
    if (ans){
        cout << "yes";
    }
    else{
        cout << "no";
    }


}