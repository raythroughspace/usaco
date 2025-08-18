#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<ssize_t> a(N);
        for (size_t i=0; i<N; ++i){
            cin >> a[i];
        }
        vector<ssize_t> suffix(N+1);
        for (ssize_t i=N-1; i>=0; --i){
            suffix[i] = suffix[i+1];
            if (a[i] > 0)
                suffix[i] += a[i];
        }
        ssize_t max_score = -SSIZE_MAX;
        for (size_t i=0; i<N; ++i){
            ssize_t score = suffix[i+1];
            if ((i+1) % 2 == 1)
                score += a[i];
            max_score = max(score, max_score);
        }
        cout << max((ssize_t)0, max_score) << "\n";
    }
}