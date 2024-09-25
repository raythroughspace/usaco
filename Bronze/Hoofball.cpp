#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    size_t N; cin >> N;
    vector<long> x(N);
    for (size_t i=0; i<N; ++i){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<vector<long>> passes(N, vector<long>());
    //find sources first (positions that don't get any passes)
    for (size_t i=0; i<N; ++i){
        if (i==0){
            passes[1].push_back(i);
        }
        else if (i==N-1){
            passes[N-2].push_back(i);
        }
        else{
            if (x[i+1] - x[i] < x[i] - x[i-1]){
                passes[i+1].push_back(i); //i passes to i+1
            }
            else{
                passes[i-1].push_back(i); //i passes to i-1
            }
        }
    }
    size_t ans = 0;
    for (size_t i=0; i<N; ++i){
        if (i+1 < N && passes[i].size() == 1 && passes[i+1].size() == 1
        && passes[i][0] == i+1 && passes[i+1][0] == i){
            ++ans;
        }
        else if (passes[i].size() == 0){
            ++ans;
        }
    }
    cout << ans;
}