#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    size_t N; cin >> N;
    vector<long> log(N);
    for (size_t i=0; i<N; ++i){
        cin >> log[i];
    }
    bool consistent = true;
    vector<long> outbreaks(N, -1); //1 = confirmed outbreak, 0 = confirmed no outbreak
    outbreaks[0] = 1;
    for (long i=0; i<N; ++i){
        if (log[i] == -1){ // no log entry
            continue;
        }
        else if (i-log[i] < 0 || outbreaks[i-log[i]] == 0){
            consistent = false;
        }
        else{
            outbreaks[i-log[i]] = 1;
        }
        // there cant be outbreaks from i-log[i] + 1 to i
        for (long j= i-log[i]+1; j<=i; ++j){
            if (j<0 || outbreaks[j] == 1){
                consistent = false;
                break;
            }
            outbreaks[j] = 0;
        }
    }
    if (consistent){
        size_t m =0;
        size_t M = 0;
        for (size_t i=0; i< N; ++i){
            if (outbreaks[i] == 1){
                ++m, ++M;
            }
            else if (outbreaks[i] == -1){
                ++M;
            }
        }
        cout << m << " " << M;
    }
    else{
        cout << -1;
    }
}