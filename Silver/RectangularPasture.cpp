#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<pair<size_t, size_t>> pts(N);
    for (size_t i=0; i<N; ++i){
        size_t a,b; cin >> a >> b;
        pts[i] = {a,b};
    }
    sort(pts.begin(), pts.end());
    for (size_t i=0; i<N; ++i){
        pts[i].first = i+1;
    }
    sort(pts.begin(), pts.end(), [](auto& left, auto& right){
        return left.second < right.second;
    });
    for (size_t i=0; i<N; ++i){
        pts[i].second = i+1;
    }
    vector<vector<ssize_t>> prefix(N+1, vector<ssize_t>(N+1));
    for (auto pt: pts){
        prefix[pt.first][pt.second] = 1;
    }
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=N; ++j){
            prefix[i][j] += prefix[i][j-1];
        }
        for (size_t j=1; j<=N; ++j){
            prefix[i][j] += prefix[i-1][j];
        }
    }
    sort(pts.begin(), pts.end());
    size_t ans = 1 + N;
    for (size_t i=0; i<N; ++i){
        for (size_t j=i+1; j<N; ++j){
            ssize_t a = pts[i].first;
            ssize_t b = pts[i].second;
            ssize_t c = pts[j].first;
            ssize_t d = pts[j].second;
            if (a > c){
                swap(a,c);
            }
            if (b > d){
                swap(b,d);
            }
            ssize_t below = prefix[c][b-1] - prefix[a][b-1];
            ssize_t above = prefix[c][N] + prefix[a][d]- prefix[c][d] - prefix[a][N];
            ans += (below + 1)*(above + 1);
        }
    }
    cout << ans;

}