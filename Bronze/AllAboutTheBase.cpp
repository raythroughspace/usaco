#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("whatbase.in","r", stdin);
    freopen("whatbase.out", "w", stdout);
    size_t K; cin >> K;
    for (size_t k=0; k<K; ++k){
        map<size_t, size_t> Xs;
        string X,Y; cin >> X >> Y;
        for (size_t i=10; i<=15000; ++i){
            Xs[(X[0] - '0')*i*i + (X[1] - '0')*i + X[2] - '0'] = i;
        }
        for (size_t i=10; i<=15000; ++i){
            size_t val = (Y[0] - '0')*i*i + (Y[1] - '0')*i + Y[2] - '0';
            if (Xs.count(val)){
                cout << Xs[val] << " " << i << "\n";
                break;
            }
        }
    }
}