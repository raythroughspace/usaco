#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,Q; cin >> N >> Q;
        vector<size_t> a(N);
        size_t sum = 0;
        size_t xor1 = 0;
        for (size_t i=0; i<N; ++i){
            cin >> a[i];
            sum += a[i];
            xor1 ^= a[i];
        }
        size_t L,R; cin >> L >> R;
        size_t maximum = sum - xor1;
        ssize_t hi = N-1;
        ssize_t lo = 0;
        pair<size_t,size_t> best = {0, N-1};

        for (ssize_t hi = N-1; hi >=0; --hi){
            if (sum - xor1 == maximum && best.second - best.first > hi - lo){
                best = {lo, hi};
            }
            while (lo +1 <= hi && (sum - a[lo]) - (xor1 ^ a[lo]) == maximum){
                if (best.second - best.first > hi - (lo + 1))
                    best = {lo+1, hi};
                sum -= a[lo];
                xor1 ^= a[lo];
                ++lo;
            }
            if (lo > 0){ // we are decreasing hi by 1 next, 
            //we can afford to decrease lo by 1 and keep length <= best length
                --lo;
                sum += a[lo];
                xor1 ^= a[lo];
            }
            sum -= a[hi];
            xor1 ^= a[hi];
        }
        cout << best.first + 1 << " " << best.second + 1 << "\n";
    }
}