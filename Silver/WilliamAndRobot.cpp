#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<ssize_t> a(N);
    multiset<ssize_t> W;
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    W.insert(max(a[0], a[1]));
    for (size_t i=2; i<N; i+=2){
        if (*W.begin() < min(a[i],a[i+1])){
            W.erase(W.begin());
            W.insert(a[i]);
            W.insert(a[i+1]);
        }
        else{
            W.insert(max(a[i], a[i+1]));
        } 
    }
    ssize_t ans = 0;
    for (ssize_t w: W){
        ans += w;
    }
    cout << ans;
}