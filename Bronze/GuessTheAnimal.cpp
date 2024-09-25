#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    size_t N; cin >> N;
    vector<unordered_set<string>> animals;
    for (size_t i=0; i<N; ++i){
        unordered_set<string> chars;
        string name; cin >> name;
        size_t K; cin >> K;
        for (size_t j=0; j<K; ++j){
            string attr; cin >> attr;
            chars.insert(attr);
        }
        animals.push_back(chars);
    }
    size_t globalmax = 0;
    for (size_t i=0; i<N; ++i){
        size_t localmax = 0;
        for (size_t j=0; j<N; ++j){
            if (i==j){
                continue;
            }
            size_t matches = 0;
            for (auto c: animals[i]){
                if (animals[j].count(c)){
                    ++matches;
                }
            }
            localmax = max(matches, localmax);
        }
        globalmax = max(globalmax, localmax);
    }
    cout << globalmax+1;
}