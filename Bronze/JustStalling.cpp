#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<size_t> b(N);
    vector<size_t> a(N);
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    for (size_t i=0; i<N; ++i){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    size_t ans = 1;
    for (ssize_t i=N-1; i>=0; --i){
        size_t ways = 0;
        for (ssize_t j=N-1; j>=0; --j){
            if (a[i] <= b[j]){
                ++ways;
            }
        }
        ans *= ways - (N-1 - i);
    }
    cout << ans;
}