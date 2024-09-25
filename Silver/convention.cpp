#include <bits/stdc++.h>
using namespace std;

bool check_possible(const vector<size_t>& cows, const size_t M, 
const size_t C, const size_t N, const size_t T){
    size_t sz = 1;
    size_t low = cows[0];
    size_t bus = 1;
    for (size_t i=1; i<N; ++i){
        if (sz < C && cows[i] - low <= T){
            ++sz;
        }
        else{ //load new bus
            sz = 1;
            low = cows[i]; 
            ++bus;
        }
    }
    return bus <= M;
}

int main(){
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    size_t N,M,C; cin >> N >> M >> C;
    vector<size_t> cows(N);
    for (size_t i=0; i<N; ++i){
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    size_t lo = 0;
    size_t hi = 10e9;
    while (lo < hi){
        size_t mid = (hi + lo)/2;
        if (check_possible(cows, M, C, N, mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << lo;
}