#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<size_t,ssize_t>> A(N); // value, original index
    for (size_t i=0; i<N; ++i){
        cin >> A[i].first;
        A[i].second = i; 
    }
    sort(A.begin(), A.end());
    size_t ans = 0;
    for (ssize_t j=0; j<N; ++j){
        ans = max<size_t>(ans, abs(j - A[j].second));
    }
    cout << ans + 1;
}