#include <bits/stdc++.h>
using namespace std;
ssize_t min_two_fences(vector<pair<ssize_t,ssize_t>>& cows, size_t N){
    vector<ssize_t> minPrefix(N); minPrefix[0]= cows[0].second;
    vector<ssize_t> maxPrefix(N); maxPrefix[0] = cows[0].second;
    vector<ssize_t> maxSuffix(N); maxSuffix[N-1] = cows[N-1].second;
    vector<ssize_t> minSuffix(N); minSuffix[N-1] = cows[N-1].second;
    for (size_t i=1; i<N; ++i){
        minPrefix[i] = min(minPrefix[i-1], cows[i].second);
        maxPrefix[i] = max(maxPrefix[i-1], cows[i].second);
    }
    for (ssize_t i=N-2; i>=0; --i){
        maxSuffix[i] = max(maxSuffix[i+1], cows[i].second);
        minSuffix[i] = min(minSuffix[i+1], cows[i].second);
    }
    ssize_t best = LONG_MAX;
    for (size_t i=0; i<N-1; ++i){
        if (cows[i].first == cows[i+1].first){
            continue;
        }
        best = min(best, (cows[i].first - cows[0].first)*(maxPrefix[i] - minPrefix[i]) + 
        (cows[N-1].first - cows[i+1].first)*(maxSuffix[i+1] - minSuffix[i+1]));
    }
    return best;
}

int main(){
    //sort by x, for every distinct value of x, keep track
    // of minPrefix[x] = minimum y so far including x and maxPrefix[x]
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<ssize_t,ssize_t>> cows(N);
    vector<pair<ssize_t,ssize_t>> ycows(N);
    for (size_t i=0; i<N; ++i){
        ssize_t x,y; cin >> x >> y;
        cows[i] = {x,y};
        ycows[i] = {y,x};
    }
    sort(cows.begin(), cows.end());
    sort(ycows.begin(), ycows.end());

    ssize_t twoFence = min(min_two_fences(cows, N), min_two_fences(ycows, N));
    ssize_t oneFence = (cows[N-1].first - cows[0].first)*(ycows[N-1].first - ycows[0].first);
    cout << max(oneFence - twoFence, (ssize_t)0);
}