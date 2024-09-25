#include <bits/stdc++.h>
using namespace std;

void color_painting(vector<vector<size_t>>& painting, size_t num,
                    size_t left, size_t right, size_t up, size_t down){
    for (size_t i=up; i<=down; ++i){
        for (size_t j=left; j<=right; ++j){
            painting[i][j] = num;
        }
    }
}
int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<size_t>> painting(N, vector<size_t>(N, 0));
    set<size_t> colors;
    vector<size_t> left(10, N+1);
    vector<size_t> right(10, 0);
    vector<size_t> up(10, N+1);
    vector<size_t> down(10, 0);
    for (size_t i=0; i<N; ++i){
        string str; cin >> str;
        for (size_t j=0; j<N; ++j){
            size_t num = str[j] - '0';
            if (num != 0){
                colors.insert(num);
            }
            painting[i][j] = num;
            left[num] = min(left[num], j);
            right[num] = max(right[num], j);
            up[num] = min(up[num], i);
            down[num] = max(down[num], i);
        }
    }
    size_t ans = 0;
    for (auto c1: colors){ // for each starting color
        bool starting = true;
        vector<vector<size_t>> copy(N, vector<size_t>(N, 0));
        color_painting(copy, c1, left[c1], right[c1], up[c1], down[c1]);
        for (auto c2: colors){
            if (c1 == c2){
                continue;
            }
            color_painting(copy, c2, left[c2], right[c2], up[c2], down[c2]);
        }
        //check if there's any c2 that overwrote the starting c1 but c1 was not overwriting in original painting
        for (size_t i=up[c1]; i<=down[c1]; ++i){
            for (size_t j=left[c1]; j<=right[c1]; ++j){
                if (painting[i][j] != c1){
                    continue; //c1 was overwriten in in original painting
                }
                if (copy[i][j] != c1){
                    starting = false;
                }
            }
        }
        if (starting){
            ++ans;
        }
    }
    cout << ans;

}