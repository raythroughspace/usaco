#include <bits/stdc++.h>
using namespace std;

bool isWin(int B, int F){
    if ((B == 0 && F == 2) || 
    (B == 2 && F == 1) ||
    (B == 1 && F == 0)){
        return true;
    }
    return false;
}

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<char> FJ(N);
    for (size_t i=0; i<N; ++i){
        char in; cin >> in;
        if (in == 'H'){
            FJ[i] = 0;
        }
        else if (in == 'P'){
            FJ[i] = 1;
        }
        else{
            FJ[i] = 2;
        }
    }
    vector<vector<vector<size_t>>> S(N+1, vector<vector<size_t>>(K+2, vector<size_t>(3)));
    for (ssize_t i=N-1; i>=0; --i){
        for (size_t k=0; k<=K+1; ++k){
            for (size_t c=0; c<3; ++c){
                if (k != K+1){ //K+1 must make a move
                    S[i][k][c] = S[i+1][k][c] + isWin(c, FJ[i]);
                }
                if (k > 0){
                    for (size_t c2=0; c2<3; ++c2){
                        S[i][k][c] = max(S[i][k][c], S[i+1][k-1][c2] + isWin(c2, FJ[i]));
                    }
                }
            }
        }
    }
    cout << S[0][K+1][0];
}