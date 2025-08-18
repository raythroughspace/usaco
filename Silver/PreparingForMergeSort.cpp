#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<size_t> a(N);
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    vector<vector<size_t>> reps;
    reps.push_back(vector<size_t>(1, a[0]));
    for (size_t i=1; i<N; ++i){
        size_t smallest = reps.back().back();
        if (a[i] < smallest){
            reps.push_back(vector<size_t>(1, a[i]));
            continue;
        }
        size_t lo = 0;
        size_t hi = reps.size() - 1;
        while (lo < hi){
            size_t mid = (lo + hi)/2;
            if (a[i] > reps[mid].back()){
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        reps[hi].push_back(a[i]);
    }
    for (const auto& rep: reps){
        for (const auto& el: rep){
            cout << el << " ";
        }
        cout << "\n";
    }
}