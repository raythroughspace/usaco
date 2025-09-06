#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t V; cin >> V;
    vector<size_t> a(10);
    size_t min_idx = 1;
    size_t curr_min = SIZE_MAX;
    for (size_t i=1; i<=9; ++i){
        cin >> a[i];
        if (a[i] <= curr_min){
            min_idx = i;
            curr_min = a[i];
        }
    }
    if (V < curr_min){
        cout << -1;
        return 0;
    }
    size_t max_digits = V/curr_min;
    ssize_t rem = V - max_digits * curr_min;
    string ans;
    size_t idx = 9;
    for (ssize_t i = max_digits-1; i>=0; --i){
        while (idx >min_idx && rem < a[idx] - curr_min){
            --idx;
        }
        if (idx > min_idx && rem >= a[idx] - curr_min){
            ans.push_back('0' + idx);
            rem -= (a[idx] - curr_min);
        } else {
            ans.push_back('0'+min_idx);
        }
    }
    cout << ans;
    
}