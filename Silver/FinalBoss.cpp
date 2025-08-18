#include <bits/stdc++.h>
using namespace std;

bool possible(const size_t mid, size_t H, const size_t N, const vector<size_t>& a, const vector<size_t>& c){
    size_t score = 0;
    for (size_t i=0; i<N; ++i){
        score += (a[i] * ((mid-1) / c[i] + 1));
    }
    return score >= H;
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t H,N; cin >> H >> N;
        vector<size_t> a(N);
        for (size_t i=0; i<N; ++i){
            cin >> a[i];
        }
        vector<size_t> c(N);
        for (size_t i=0; i<N; ++i){
            cin >> c[i];
        }
        size_t lo = 1;
        size_t hi = 1e11;
        while (lo < hi){
            size_t mid = (lo + hi)/2;
            if (!possible(mid, H, N, a, c)){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        cout << lo << "\n";
    }
}