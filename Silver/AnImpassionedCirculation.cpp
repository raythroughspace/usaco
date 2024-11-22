#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N, Q; string S;
    cin >> N >> S >> Q;
    for (size_t q=0; q<Q; ++q){
        size_t m; char c; cin >> m >> c;
        size_t hi = 0;
        size_t count = 0;
        size_t ans = 0;
        for (size_t i=0; i<N; ++i){
            assert(hi>=i);
            while (count < m && hi < N){
                if (S[hi] != c){
                    ++count;
                }
                ++hi;
            }
            //count is m
            while (S[hi] == c){
                ++hi;
            }
            ans = max(ans, hi - i);

            if (S[i] != c){
                --count;
            }

        }
        cout << ans << "\n";
    }

}