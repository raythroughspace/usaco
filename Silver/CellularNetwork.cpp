#include <bits/stdc++.h>
using namespace std;

int main(){
    // for each city, find closest cell tower. r = max of distances over all cities
    size_t N,M; cin >> N >> M;
    vector<ssize_t> A(N);
    vector<ssize_t> B(M);
    for (size_t i=0; i<N; ++i){
        cin >> A[i];
    }
    for (size_t i=0; i<M; ++i){
        cin >> B[i];
    }
    size_t r = 0;
    for (size_t i=0; i<N; ++i){
        size_t local_min = SIZE_MAX;
        auto after = upper_bound(B.begin(), B.end(), A[i]);
        if (after != B.begin()){
            auto before = after -1;
            local_min = min<size_t>(abs(A[i] - *before), local_min);
        }
        if (after != B.end()){
            local_min = min<size_t>(abs(A[i] - *after), local_min);
        }
        r = max(local_min, r);
    }
    cout << r;
}