#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,Q; cin >> N >> Q;
        vector<size_t> maxpref(N);
        for (size_t i=0; i<N; ++i){
            cin >> maxpref[i];
            --maxpref[i];
            if (i>0){
                maxpref[i] = max(maxpref[i], maxpref[i-1]);
            }
        }
        vector<char> S(N);
        for (size_t i=0; i<N; ++i){
            cin >> S[i];
        }
        set<size_t> badIdx;
        for (size_t i=0; i<N-1; ++i){
            if (S[i] == 'L' && S[i+1] == 'R' && maxpref[i] != i){
                badIdx.insert(i);
            }
        }
        for (size_t q=0; q<Q; ++q){
            size_t i; cin >> i;
            --i;
            if (S[i] == 'L'){
                if (S[i-1] == 'R' && S[i+1] == 'R'){ // good
                    badIdx.erase(i);
                }
                else if (S[i-1] == 'L' && S[i+1] == 'R'){ //
                    badIdx.erase(i);
                    if (maxpref[i-1] != i-1){
                        badIdx.insert(i-1);
                    }
                }
                else if (S[i-1] == 'L' && S[i+1] == 'L'){
                    if (maxpref[i-1] != i-1){
                        badIdx.insert(i-1);
                    }
                }
                S[i] = 'R';
            }
            else{
                if (S[i+1] == 'L' && S[i-1] == 'L' && badIdx.count(i-1)){
                    badIdx.erase(i-1);
                }
                else if (S[i+1] == 'R' && S[i-1] == 'R' && maxpref[i] != i){
                    badIdx.insert(i);
                }
                else if (S[i-1] == 'L' && S[i+1] == 'R'){
                    badIdx.erase(i-1);
                    if (maxpref[i] != i){
                        badIdx.insert(i);
                    }
                }
                S[i] = 'L';
            }
            if (badIdx.size() == 0){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
    
        }

    }
}