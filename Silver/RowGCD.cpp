#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,M; cin >> N >> M;
    vector<size_t> a(N);
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    vector<size_t> b(M);
    for (size_t i=0; i<M; ++i){
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    for (size_t i=0; i<N-1; ++i){
        a[i] = a[i] - a[i+1];
    }
    size_t g = 0;
    for (size_t i=0; i<N-1; ++i){
        g = gcd(g, a[i]);
    }

    for (size_t i=0; i<M; ++i){
        cout << gcd(g, a[N-1] + b[i]) << " ";
    }

}