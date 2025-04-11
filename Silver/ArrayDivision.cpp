#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<size_t>& x, size_t K, size_t mid){
    size_t sum = 0;
    for (size_t i=0; i< x.size(); ++i){
        if (x[i] > mid){
            return false;
        }
        if (sum + x[i] > mid){
            sum = 0;
            --K;
        }
        sum += x[i];
        if (K == 0){
            return false;
        }
    }
    return true;
}

int main(){
    size_t N,K; cin >> N >> K;
    vector<size_t> x(N);
    for (size_t i=0; i<N; ++i){
        cin >> x[i];
    }
    size_t lo = 1;
    size_t hi = 1e16;
    while (lo < hi){
        size_t mid = (lo + hi - 1) / 2;
        if (possible(x, K, mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << lo;
}