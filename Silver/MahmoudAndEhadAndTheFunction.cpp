#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M,Q; cin >> N >> M >> Q;
    ssize_t aSum = 0;
    vector<ssize_t> b(M);
    for (size_t i=0; i<N; ++i){
        ssize_t a; cin >> a;
        if (i % 2 == 0){
            aSum += a;
        }
        else{
            aSum -= a;
        }
    }
    for (size_t i=0; i<M; ++i){
        cin >> b[i];
    }
    vector<ssize_t> bSum(M-N+1);
    for (size_t i=0; i<N; ++i){
        if (i % 2 == 0){
            bSum[0] += b[i];
        }
        else{
            bSum[0] -= b[i];
        }
    }

    for (size_t j=1; j<=M-N; ++j){
        if (N % 2 == 0){
            bSum[j] = - bSum[j-1] + b[j-1] - b[N-1 + j];
        }
        else{
            bSum[j] = - bSum[j-1] + b[j-1] + b[N-1 +j];
        }
    }
    sort(bSum.begin(), bSum.end());
    
    for (size_t q = 0; q<=Q; ++q){
        if (q != 0){
            ssize_t l,r,x; cin >> l >> r >> x;
            --l; --r;
            if ((l- r) % 2 == 0){
                if (l % 2 == 0){
                    aSum += x;
                }
                else{
                    aSum -= x;
                }
            }
        }
        auto lo = upper_bound(bSum.begin(), bSum.end(), aSum);
        size_t ans;
        if (lo == bSum.end()){
            --lo;
            ans = abs(aSum - *lo);
        }
        else{
            ans = abs(aSum - *lo);
            if (lo != bSum.begin()){
                --lo;
                ans = min<size_t>(ans, abs(aSum - *lo));
            }
        }
        cout << ans << "\n";
    }
}