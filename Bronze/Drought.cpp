#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<ssize_t> hunger(N);
        for (size_t i=0; i<N; ++i){
            cin >> hunger[i];
        }
        ssize_t ans = 0;
        if (N==1){
            cout << ans << "\n";
            continue;
        }
        vector<ssize_t> evens(1, hunger[1] - hunger[0]);
        for (size_t i=2; i<N; ++i){
            if (i % 2 == 1){
                evens.push_back(hunger[i] - (hunger[i-1] - evens[evens.size() - 1]));
            }
        }
        ssize_t k;
        if (N % 2 == 1){
            k = hunger[hunger.size() - 1] - evens[evens.size() - 1];
        }
        else{
            k = hunger[0];
            for (size_t i=2; i<N; i+=2){
                k = min(k, hunger[i] - evens[(i-2)/2]);
            }
        }

        for (size_t i=0; i<N-1; ++i){
            if (hunger[i] - k <= 0){
                continue;
            }
            ans +=2*(hunger[i] - k);
            hunger[i+1] -= (hunger[i] - k);
            hunger[i] = k;
        }
        bool possible = true;
        for (size_t i=0; i<N; ++i){
            if (hunger[i] != k || k<0){
                possible = false;
            }
        }
        if (possible){
            cout << ans << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}