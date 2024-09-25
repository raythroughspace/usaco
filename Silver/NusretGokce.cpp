#include <bits/stdc++.h>
using namespace std;

int main(){
    ssize_t N,M; cin >> N >> M;
    map<ssize_t, set<ssize_t>> salt2idx;
    vector<ssize_t> salt(N);
    for (ssize_t i=0; i<N; ++i){
        cin >> salt[i];
        salt2idx[salt[i]].insert(i);
    }
    for (ssize_t i=0; i<N; ++i){
        auto maxEls = max_element(salt2idx.begin(), salt2idx.end())->second;
        ssize_t idx = *maxEls.begin();
        if (idx > 0 && salt[idx] - salt[idx-1] > M){
            salt2idx[salt[idx-1]].erase(idx-1);
            salt2idx[salt[idx]-M].insert(idx-1);
            salt[idx-1] = salt[idx]-M;
        }
        if (idx < N-1 && salt[idx] - salt[idx+1] > M){
            salt2idx[salt[idx+1]].erase(idx+1);
            salt2idx[salt[idx]-M].insert(idx+1);
            salt[idx+1] = salt[idx]-M;
        }
        if (salt2idx[salt[idx]].size() == 1){
            salt2idx.erase(salt[idx]);
        }
        else{
            salt2idx[salt[idx]].erase(idx);
        }
    }
    for (auto el: salt){
        cout << el << " ";
    }

}