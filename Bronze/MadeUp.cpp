#include <bits/stdc++.h>
using namespace std;

int main(){
    long N; cin >> N;
    map<long,long> A;
    vector<long> B(N);
    vector<long> C(N);
    for (long i=0; i<N; ++i){
        long a; cin >> a;
        A[a]++;
    }
    for (long i=0; i<N; ++i){
        cin >> B[i];
    }
    for (long i=0; i<N; ++i){
        cin >> C[i];
    }
    map<long, long> BC;
    for (long i=0; i<N; ++i){
        BC[B[C[i]-1]]++;
    }
    long nPairs = 0;
    for (auto key: A){
        nPairs += A[key.first] * BC[key.first];
    }
    cout << nPairs;
}