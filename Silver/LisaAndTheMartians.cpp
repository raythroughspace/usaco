#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,K; cin >> N >> K;
        vector<pair<size_t, size_t>> a(N);
        for (size_t i=0; i<N; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        size_t mini = LONG_LONG_MAX;
        size_t x,y;
        for (size_t i=1; i<N; ++i){
            if (mini > (a[i].first ^ a[i-1].first)){
                x = a[i].second; y = a[i-1].second;
                mini = (a[i].first ^ a[i-1].first);
            }
        }
        cout << x+1 << " "<< y+1 << " " << (a[y].first ^ ((1 << K) -1)) << "\n";
    }
}