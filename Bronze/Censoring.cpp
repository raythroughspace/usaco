#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string S,T; cin >> S >> T;
    string censored = S.substr(0, T.size());
    long pos = 0;
    for (size_t i=T.size(); i< S.size(); ++i){
        if (censored.substr(pos, S.size()) == T){
            censored.resize(pos);
        }
        censored += S[i];
        pos = max((long) 0, (long) (censored.size() - T.size()));
    }
    cout << censored;
}