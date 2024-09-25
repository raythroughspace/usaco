#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N,Q; cin >> N >> Q;
    vector<vector<size_t>> forest(N+1, vector<size_t>(N+1));
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=N; ++j){
            char c; cin >> c;
            if (c == '*'){
                forest[i][j] = 1;
            }
            forest[i][j] += forest[i][j-1];
        }
        for (size_t j=1; j<=N; ++j){
            forest[i][j] += forest[i-1][j];
        }
    }
    for (size_t q=0; q<Q; ++q){
        size_t a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << forest[c][d] - forest[c][b-1] - forest[a-1][d] + forest[a-1][b-1] << "\n";
    }
}