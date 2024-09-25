#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<size_t,ssize_t>> milkNCows(N); //pairs (milk output, ncows)
    for (size_t i=0; i<N; ++i){
        cin >> milkNCows[i].second >> milkNCows[i].first;
    }
    sort(milkNCows.begin(), milkNCows.end());
    ssize_t hi = N-1;
    ssize_t lo = 0;
    size_t maxTime = 0;
    while (hi >= lo){
        if (milkNCows[hi].second <= 0){
            --hi;
        }
        else if (milkNCows[lo].second <= 0){
            ++lo;
        }
        else{
            maxTime = max(maxTime, milkNCows[lo].first + milkNCows[hi].first);
            ssize_t pairs = min(milkNCows[lo].second, milkNCows[hi].second);
            milkNCows[lo].second -= pairs;
            milkNCows[hi].second -= pairs;
        }
    }
    cout << maxTime;
}