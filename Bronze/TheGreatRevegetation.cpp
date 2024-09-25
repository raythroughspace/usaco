#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    vector<vector<size_t>> cows(M+1);
    vector<vector<size_t>> fields(N+1);
    string coloring(N+1, '0');
    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a >> b;
        cows[i+1].push_back(a);
        cows[i+1].push_back(b);
        fields[a].push_back(i+1);
        fields[b].push_back(i+1);
    }
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=4; ++j){ // try coloring field i with color j
            bool valid = true;
            for (size_t cow: fields[i]){
                for (auto field: cows[cow]){
                    if (coloring[field] - '0' == j){
                        valid = false;
                    }
                }
            }
            if (valid){
                coloring[i] = j + '0';
                break;
            }
        }
    }

    cout << coloring.substr(1);
}