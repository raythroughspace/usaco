#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> cows(N);
    for (size_t i=0; i<N; ++i){
        cin >> cows[i];
    }
    size_t ans = 0;
    for (size_t i=0; i<N; ++i){
        bool isSorted = true;
        for (size_t j= i+1; j<N; ++j){
            if (cows[j] < cows[j-1]){
                isSorted = false;
            }
        }
        if (isSorted){
            break;
        }
        ++ans;
    }
    cout << ans;
}