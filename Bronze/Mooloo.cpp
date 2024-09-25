#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,K; cin >> N >> K;
    vector<size_t> schedule(N);
    for (size_t i=0; i<N; ++i){
        cin >> schedule[i];
    }
    size_t cost = K+1;
    for (size_t i=1; i<N; ++i){
        if (schedule[i] - schedule[i-1] > K+1){
            cost += K+1;
        }
        else{
            cost += (schedule[i] - schedule[i-1]);
        }
    }
    cout << cost;
}