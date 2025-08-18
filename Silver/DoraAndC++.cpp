#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,a,b; cin >> N >> a >> b;
        vector<size_t> c(N);
        for (size_t i=0; i<N; ++i){
            cin >> c[i];
        }
        size_t d = gcd(a,b);
        for (size_t i=0; i<N; ++i){
            c[i] -= (c[i]/d)*d;
        }
        sort(c.begin(), c.end());
        size_t min_diff = c[N-1] - c[0];
        for (size_t i=1; i<N; ++i){
            c[i-1] += d;
            size_t range = max(c[N-1] - c[i], c[i-1] - c[i]);
            min_diff = min(min_diff, range);
        }
        cout << min_diff << "\n";
    }
}