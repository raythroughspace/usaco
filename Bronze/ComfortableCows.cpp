#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    map<pair<size_t,size_t>, size_t> cows; // (x,y, #adj cows)
    size_t ans = 0;
    set<ssize_t> dir = {-1,1};
    for (size_t i=0; i<N; ++i){
        size_t x,y; cin >> x >> y;
        for (auto d: dir){
            if (cows.count({x+d, y})){
                ++cows[{x+d,y}];
                ++cows[{x,y}];
                if (cows[{x+d,y}] == 4){
                    --ans;
                }
                else if (cows[{x+d, y}] == 3){
                    ++ans;
                }
            }
            if (cows.count({x, y+d})){
                ++cows[{x,y+d}];
                ++cows[{x,y}];
                if (cows[{x,y+d}] == 4){
                    --ans;
                }
                else if (cows[{x, y+d}] == 3){
                    ++ans;
                }
            }
        }
        if (cows[{x,y}] == 3){
            ++ans;
        }
        cout << ans << "\n";
    }
}