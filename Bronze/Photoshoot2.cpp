#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    map<size_t, size_t> a;
    set<size_t>  validIdx;
    vector<size_t> b(N);
    for (size_t i=0; i<N; ++i){
        size_t ai; cin >> ai;
        a[ai] = i;
        validIdx.insert(i);
    }
    for (size_t i=0; i<N; ++i){
        cin >> b[i];
    }
    size_t ans = 0;
    for (size_t i=0; i<N; ++i){
        if (a[b[i]] != *(validIdx.begin())){
            ++ans;
        }
        validIdx.erase(a[b[i]]); 
    }
    cout << ans;
}