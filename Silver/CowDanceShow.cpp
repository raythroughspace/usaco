#include <bits/stdc++.h>
using namespace std;

bool check_time(const vector<size_t>& durations, size_t K, size_t T){
    priority_queue<size_t, vector<size_t>, greater<size_t>> stage;
    size_t time = 0;
    for (size_t k=0; k<durations.size(); ++k){
        if (k < K){
            stage.push(durations[k]);
        }
        else{
            time = stage.top();
            stage.pop();
            stage.push(durations[k] + time);
        }
    }
    for (size_t k=0; k<K; ++k){
        time = max(time, stage.top());
        stage.pop();
    }
    return time <= T;
    
}
int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    size_t N, T; cin >> N >> T;
    vector<size_t> durations(N);
    for (size_t i=0; i<N; ++i){
        cin >> durations[i];
    }

    size_t lo = 1;
    size_t hi = N;
    while (lo < hi){
        size_t K = (hi + lo)/2;
        if (!check_time(durations, K, T)){
            // have to try higher values
            lo = K + 1;
        }
        else{
            //  K works see if can try lower
            hi = K;
        }
    }
    cout << hi;
}