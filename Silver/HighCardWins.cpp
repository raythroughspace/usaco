#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> cards(2*N+1, 1);
    for (size_t i=0; i<N; ++i){
        size_t a; cin >> a;
        cards[a] = 0;
    }
    size_t ans = 0;
    size_t Bessie = 0;
    for (size_t i=2*N; i>0; --i){
        if (cards[i] == 1){
            ++Bessie;
        }
        else{
            if (Bessie >0){
                --Bessie;
                ++ans;
            }
        }
    }
    cout << ans;
}