#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,K,Q; cin >> N >> K >> Q;
    vector<vector<size_t>> b(N, vector<size_t>(K));
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<K; ++j){
            cin >> b[i][j];
            if (i>0){
                b[i][j] |= b[i-1][j];
            }
        }
    }
    vector<vector<size_t>> bT(K, vector<size_t>(N));
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<K; ++j){
            bT[j][i] = b[i][j];
        }
    }
    for (size_t q=0; q<Q; ++q){
        size_t lo = 0; size_t hi = N-1;
        bool invalid = false;
        size_t M; cin >> M;
        for (size_t m=0; m<M; ++m){
            size_t R; char O; size_t C; cin >> R >> O >> C;
            --R;
            if (O == '<'){ // biR < C, change hi to be largest country satisfying bhiR < C
                auto it = lower_bound(bT[R].begin(), bT[R].end(), C); //it is larger or equal C
                if (it == bT[R].begin()){ //every country has biR >= C
                    invalid = true;
                }
                --it;
                hi = min<size_t>(hi, distance(bT[R].begin(), it));
            }
            else{
                // want biR > C, change lo to be smallest country satisfying bloR > C
                auto it = upper_bound(bT[R].begin(), bT[R].end(), C); //it is larger than C
                if (it == bT[R].end()){
                    invalid = true;
                }
                lo = max<size_t>(lo, distance(bT[R].begin(), it));
            }
        }
        if (lo<=hi && !invalid){
            cout << lo + 1 << "\n";
        }
        else{
            cout << "-1\n";
        }
    }

}