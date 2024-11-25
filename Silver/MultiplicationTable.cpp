#include <bits/stdc++.h>
using namespace std;

// true if number of elements smaller than k is greater than N*N/2
bool geqHalf(size_t k, size_t N){
    size_t smaller = 0; // number of elements smaller or equal to k
    for (size_t i=1; i<=N; ++i){
        //find largert mid such that mid*i < k
        size_t lo = 1; size_t hi = N;
        while (lo < hi){
            size_t mid = (hi+lo+1)/2;
            if (mid*i <= k){
                lo = mid;
            }
            else{
                hi = mid -1;
            }
        }
        smaller += lo;
    }
    return (smaller > (N*N)/2);
}
int main(){
    size_t N; cin >> N;
    size_t lo = 1;
    size_t hi = N*N;
    while (lo < hi){
        // find smallest element with greater than N*N/2 elements before it
        size_t mid = (hi+lo)/2;
        if (geqHalf(mid, N)){
            //mid works
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << hi;
}