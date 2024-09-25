#include <bits/stdc++.h>
using namespace std;

bool check_possible(const vector<pair<size_t,size_t>>& endpoints, const size_t N, 
const size_t M, const size_t D){
    size_t low = endpoints[0].first; // first cow in lowest endpoint possible
    size_t idx = 0; // idx of endpoints
    for (size_t i=1; i<N; ++i){
        if (low + D <= endpoints[idx].second){
            // can put another cow in current interval
            low += D;
        }
        else{
            // need to keep going up intervals
            while (low + D > endpoints[idx].second){
                if (idx == M-1){
                    return false; // no more intervals
                }
                ++idx;
            }
            // in this interval, we have low + D <= endpoints[idx].second
            low = max(low+D, endpoints[idx].first);
        }
    }
    return true;
}

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    vector<pair<size_t,size_t>> endpoints(M);
    for (size_t i=0; i<M; ++i){
        cin >> endpoints[i].first >> endpoints[i].second;
    }
    sort(endpoints.begin(), endpoints.end());
    ssize_t lo = 0;
    ssize_t hi = 1e18;
    while (lo < hi){
        ssize_t mid = (lo + hi + 1)/2;
        if (check_possible(endpoints, N, M, mid)){
            //try higher or equal
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << hi;
}