#include <bits/stdc++.h>
using namespace std;
// create NxN grid
//for each pair of K K^2
//  keep track of range(x) and range(y)
//  loop through all combinations of (dx1,dy1) and (dx2,dy2) in range: N^4
//      loop through first grid:
//          if square is #: map # to (i+dx1, j+dy1)
//      loop through second grid:
//          if square is #: map # to (i+dx2, j+dy2)
//      loop through entire grid and see if matches figure:
//          if matches cout indices and break
vector<pair<long,long>> getDxDy(vector<string>& grid, size_t N){
    long loX = N; long hiX = 0;
    long loY = N; long hiY = 0;
    for (long i=0; i<N; ++i){
        for (long j=0; j<N; ++j){
            if (grid[i][j] == '#'){
                loX = min(i, loX);
                hiX = max(i, hiX);
                loY = min(j, loY);
                hiY = max(j, hiY);
            }
        }
    }
    vector<long> Dx;
    for (long x = -loX; x<=0; ++x){
        Dx.push_back(x);
    }
    for (long x =0; x< N-hiX; ++x){
        Dx.push_back(x);
    }
    vector<long> Dy; 
    for (long y = -loY; y<=0; ++y){
        Dy.push_back(y);
    }
    for (long y=0; y< N-hiY; ++y){
        Dy.push_back(y);
    }
    vector<pair<long,long>> DxDy;
    for (auto x: Dx){
        for (auto y: Dy){
            DxDy.push_back({x,y});
        }
    }
    return DxDy;
}


int main(){
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<string> figure(N);
    vector<vector<string>> pieces(K, vector<string>(N));
    for (size_t i=0; i<N; ++i){
        cin >> figure[i];
    }
    for (size_t i=0; i<K; ++i){
        for (size_t j=0; j<N; ++j){
            cin >> pieces[i][j];
        }
    }
    bool found = false;
    for (size_t i=0; i<K; ++i){
        for (size_t j=i+1; j<K; ++j){
            vector<pair<long,long>> piece1DxDy = getDxDy(pieces[i], N);
            vector<pair<long,long>> piece2DxDy = getDxDy(pieces[j], N);
            for (auto d1: piece1DxDy){
                for (auto d2: piece2DxDy){
                    bool overlap = false;
                    vector<string> assemble(N, string(N, '.')); //make new empty grid
                    for (size_t n=0; n<N; ++n){
                        for (size_t m=0; m<N; ++m){
                            if (pieces[i][n][m] == '#'){
                                assemble[n+d1.first][m+d1.second] = '#';
                            }
                            if (pieces[j][n][m] == '#'){
                                if (assemble[n+d2.first][m+d2.second] == '#'){
                                    overlap = true;
                                }
                                assemble[n+d2.first][m+d2.second] = '#';
                            }
                        }
                    }
                    bool match = true;
                    for (size_t n=0; n<N; ++n){
                        if (assemble[n] != figure[n]){
                            match = false;
                        }
                    }
                    if (match && !overlap && !found){
                        cout << i+1 << " " << j+1;
                        found = true;
                    }
                }
            }
        }
    }
}