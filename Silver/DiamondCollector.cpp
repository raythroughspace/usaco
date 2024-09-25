#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<size_t> diamonds(N);
    for (size_t i=0; i<N; ++i){
        cin >> diamonds[i];
    }
    sort(diamonds.begin(), diamonds.end());
    vector<ssize_t> intervalSz(N); // calculate number of elements in [diamond[i], diamond[i] + K]
    ssize_t maxIdx = 0;
    for (ssize_t i=0; i<N; ++i){
        while (maxIdx + 1 < N && diamonds[maxIdx+1] <= diamonds[i] + K){
            ++maxIdx;
        }
        intervalSz[i] = maxIdx - i + 1;
    }
    vector<ssize_t> maxSuffix(N+1);
    for (ssize_t i=N-1; i>=0; --i){
        maxSuffix[i] = max(maxSuffix[i+1], intervalSz[i]);
    }
    ssize_t ans = 0;
    maxIdx = 0;
    for (size_t i=0; i<N; ++i){
        while (maxIdx <N && diamonds[maxIdx] <= diamonds[i] + K){
            ++maxIdx;
        }
        //maxIdx is first diamond outside range of [diamond[i], diamond[i] + K] or maxIdx = N
        ans = max(ans, intervalSz[i] + maxSuffix[maxIdx]);
    }
    cout << ans;
}