#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    size_t N; cin >> N;
    vector<ssize_t> firstGame(2*N+1);
    vector<ssize_t> secondGame(2*N+1);
    for (size_t i=0; i<N; ++i){
        size_t a; cin >> a;
        if (i < N/2){
            firstGame[a] = -1;
        }
        else{
            secondGame[a] = -1;
        }
    }
    vector<size_t> BessieCards;
    for (size_t i=1; i<=2*N; ++i){
        if (firstGame[i] == -1 || secondGame[i] == -1){
            continue;
        }
        BessieCards.push_back(i);
    }
    for (size_t i=0; i<N; ++i){
        if (i<N/2){
            secondGame[BessieCards[i]] = 1;
        }
        else{
            firstGame[BessieCards[i]] = 1;
        }
    }
    size_t ans = 0;
    size_t Bessie = 0;
    for (size_t i=2*N; i> 0; --i){
        if (firstGame[i] == 1){
            ++Bessie;
        }
        if (Bessie >0 && firstGame[i] == -1){
            ++ans;
            --Bessie;
        }
    }
    Bessie = 0;
    for (size_t i=1; i<=2*N; ++i){
        if (secondGame[i] == 1){
            ++Bessie;
        }
        if (Bessie >0 && secondGame[i] == -1){
            --Bessie;
            ++ans;
        }
    }
    cout << ans;
}