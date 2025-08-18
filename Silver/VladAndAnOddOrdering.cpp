#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,K; cin >> N >> K;
        size_t pow = 1;
        for (size_t i=0; i<N; ++i){
            if (i != 0)
                pow *= 2;
            size_t count = ((N/pow) - 1)/2;
            if (K > count + 1){
                K -= (count+1);
            } else {
                // found answer
                cout << pow * (2 * (K-1) + 1) << "\n";
                break;
            }
        }
    }
}