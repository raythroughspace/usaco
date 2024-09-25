#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> cows(N);
    size_t bessie = 0;
    size_t bessieIdx = 0;
    for (size_t i=0; i<N; ++i){
        cin >> cows[i];
    }
    for (size_t i=0; i<N; ++i){
        // exclude i
        bool isBessie = true;
        vector<size_t> copy(cows);
        copy.erase(copy.begin() + i);
        for (size_t j=1; j<N-1; ++j){
            if (copy[j] < copy[j-1]){
                isBessie = false;
            }
        }
        if (isBessie){
            bessie = cows[i];
            bessieIdx = i;
        }
    }
    size_t ans = 0;
    size_t prev = 0;
    while (bessieIdx > 0 && bessie < cows[bessieIdx - 1]){// swap left
        if (prev != cows[bessieIdx-1]){
            ++ans;
        }
        prev = cows[bessieIdx - 1];
        --bessieIdx;
    }
    while (bessieIdx < N-1 && bessie > cows[bessieIdx + 1]){
        if (prev != cows[bessieIdx + 1]){
            ++ans;
        }
        prev = cows[bessieIdx + 1];
        ++bessieIdx;
    }
    cout << ans;
}