#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<ssize_t> b(2*N);
        for (size_t i=0; i<2*N; ++i){
            cin >> b[i];
        }
        sort(b.rbegin(), b.rend());
        ssize_t a = 0;
        vector<ssize_t> odds;
        vector<ssize_t> evens;
        for (size_t i=0; i<N+1; ++i){
            a += b[i];
            odds.push_back(b[i]);
        }
        for (size_t i=N+1; i<2*N; ++i){
            a -= b[i];
            evens.push_back(b[i]);
        }
        evens.push_back(a);
        for (size_t i=0; i<N; ++i){
            cout << odds[i] << " ";
            cout << evens[i] << " ";
        }
        cout << odds[N] << "\n";
    }
}