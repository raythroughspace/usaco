#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<size_t> p(N);
        for (size_t i=0; i<N; ++i){
            cin >> p[i];
        }
        size_t min_inv = 0;
        for (size_t i=1; i<=N; ++i){
            size_t inv = 0;
            for (size_t j=0; j<N; ++j){
                if (p[j] == i)
                    break;
                if (p[j] > i)
                    ++inv;
            }
            min_inv += min(inv, N-inv-i);
        }
        cout << min_inv << "\n";
    }

}