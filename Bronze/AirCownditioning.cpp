#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<ssize_t> p(N);
    vector<ssize_t> t(N);
    for (size_t i=0; i<N; ++i){
        cin >> p[i];
    }
    for (size_t i=0; i<N; ++i){
        cin >> t[i];
    }
    ssize_t ans = 0;
    ssize_t credit = 0;
    for (size_t i=0; i<N; ++i){
        if (p[i] >= t[i]){ // increase temp for ith cow
            if (credit < p[i] - t[i]){ // not enough credit
                if (credit >=0){
                    ans += (p[i] - t[i] - credit);
                }
                else{
                    ans += (p[i] - t[i]);
                }
            }
        }
        else{
            if (credit > p[i] - t[i]){ //not enough credit to decrease to p[i]
                if (credit <0){
                    ans += abs(p[i] - t[i] - credit);
                }
                else{
                    ans += (t[i] - p[i]);
                }
            }
        }
        credit = (p[i] - t[i]);
    }
    cout << ans;
}