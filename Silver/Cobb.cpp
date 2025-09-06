#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,K; cin >> N >> K;
        vector<ssize_t> a(N+1);
        for (size_t i=1; i<=N; ++i)
            cin >> a[i];
        ssize_t maximum = -SSIZE_MAX;
        if (N<1000){
            for (size_t i=1; i<=N; ++i){
                for (size_t j=1; j<=N; ++j){
                    if (i == j)
                        continue;
                    maximum = max<ssize_t>(maximum, i*j - K*(a[i]|a[j]));
                }
            }
        } else {
            for (size_t j=N-101; j<=N; ++j){
                for (size_t i=1; i<j; ++i){
                    maximum = max<ssize_t>(maximum, i*j - K*(a[i]|a[j]));
                }
            }
        }
        cout << maximum << "\n";
    }
}