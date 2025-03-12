#include <bits/stdc++.h>
using namespace std;

struct loc {
    ssize_t x,y;
    size_t t;

    bool operator<(const loc &other) {
        if (other.t != t){
            return t < other.t;
        }
        if (other.x != x){
            return x < other.x;
        }
        return y < other.y;
    }

    bool operator==(const loc &other){
        return t == other.t && y == other.y && x == other.x;
    }
};

bool compare(const loc& l1, const loc& l2){
    return ((l1.x - l2.x)*(l1.x - l2.x) + (l1.y - l2.y)*(l1.y - l2.y) <= (l1.t - l2.t)*(l1.t - l2.t));
}


int main(){
    size_t G,N; cin >> G >> N;
    vector<loc> grazings(G);
    vector<loc> alibi(N);
    for (size_t i=0; i<G; ++i){
        cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    }
    for (size_t i=0; i<N; ++i){
        cin >> alibi[i].x >> alibi[i].y >> alibi[i].t;
    }
    sort(grazings.begin(), grazings.end());

    size_t ans = 0;
    for (size_t i=0; i<N; ++i){
        //check if alibi "fits" in grazings
        auto lo = lower_bound(grazings.begin(), grazings.end(), alibi[i]);
        if (lo != grazings.end() && *lo == alibi[i])
            continue;
        
        
        if (lo != grazings.begin()){
            auto before = lo -1;
            if (compare(*before, alibi[i])){
                if (lo == grazings.end())
                    continue;
                if (compare(*lo, alibi[i]))
                    continue;
            }
        }
        else{
            if (compare(*lo, alibi[i]))
                continue;
        }
        ++ans;
    }
    cout << ans;
}