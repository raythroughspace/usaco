#include <bits/stdc++.h>
using namespace std;
 
bool possible(double time, size_t N, vector<ssize_t>& x, vector<ssize_t>& v){
    double xlo = -1e9, xhi = 1e9;
    for (size_t i=0; i<N; ++i){
        xlo = max<double>(xlo, x[i] - v[i]*time);
        xhi = min<double>(xhi, x[i] + v[i]*time);
    }
    return (xhi - xlo >= 0);
}
 
int main(){
    size_t N; cin >> N;
    vector<ssize_t> x(N), v(N);
    for (size_t i=0; i<N; ++i){
        cin >> x[i];
    }
    for (size_t i=0; i<N; ++i){
        cin >> v[i];
    }
    ssize_t lo = 0;  
    ssize_t hi = 1e18; // represents time = 1e18 * 1e-9 = 1e9
    size_t best = 1e18; 
    while (lo <= hi){
        size_t mid = (lo+hi)/2;
        if (possible(mid * 1e-9, N, x, v)){
            hi = mid -1;
            best = min(best, mid);
        }
        else{
            lo = mid + 1;
        }
    }
    cout.precision(12);
    cout << best * 1e-9;
}
