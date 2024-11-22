#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t X,N; cin >> X >> N;
    set<size_t> pos;
    pos.insert(0);
    pos.insert(X);
    map<size_t,size_t> dis; dis[X] = 1;
    for (size_t i=0; i<N; ++i){
        size_t p; cin >> p;
        auto ptr = pos.lower_bound(p);
        size_t hi = *ptr;
        --ptr;
        size_t lo = *ptr;
        --dis[hi - lo];
        if (dis[hi - lo] == 0){
            dis.erase(hi-lo);
        }
        ++dis[hi - p];
        ++dis[p - lo];
        pos.insert(p);
        auto ans = dis.end();
        --ans;
        cout << ans->first << " ";
    }
}