#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<size_t> flowers(N);
    for (size_t i=0; i<N; ++i){
        cin >> flowers[i];
    }
    size_t ans = 0;
    for (size_t i=0; i<N; ++i){
        for (size_t j=i; j<N; ++j){
            size_t average = 0;
            bool containsAverage = false;
            for (size_t k=i; k<=j; ++k){
                average += flowers[k];
            }
            for (size_t k=i; k<=j; ++k){
                if (average == (j - i + 1)*flowers[k]){
                    containsAverage = true;
                }
            }
            if (containsAverage){
                ++ans;
            }
        }
    }
    cout << ans;
}