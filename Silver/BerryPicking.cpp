#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("berries.in", "r" ,stdin);
    freopen("berries.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<size_t> B(N);
    for (size_t i=0; i<N; ++i){
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    size_t best = 0;
    for (size_t m=1; m<=1000; ++m){
        vector<size_t> copy(B);
        size_t amount = 0;
        for (auto& b: copy){
            amount += b/m;
            b -= (b/m) * m;
        }
        if (amount < K/2){
            continue;
        }
        else if (amount >= K){
            best = max(best, K/2 * m);
            continue;
        }
        amount -= K/2;
        priority_queue<size_t, vector<size_t>> maxHeap(copy.begin(), copy.end());
        size_t ans = amount * m;
        while (amount != K/2 && !maxHeap.empty()){
            size_t el = maxHeap.top();
            maxHeap.pop();
            if (el > m){
                el -= m;
                ans += m;
                maxHeap.push(el);
            }
            else{
                ans += el;
            }
            ++amount;
        }
        best = max(best, ans);
    }
    cout << best;
}