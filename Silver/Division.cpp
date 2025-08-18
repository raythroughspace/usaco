#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,M; cin >> N >> M;
        size_t d = gcd(N,M);
        if (d < M){
            cout << N << "\n";
        } else {
            size_t ans = 1;
            for (size_t i=2; i<=1e5; ++i){
                if (d % i == 0){
                    size_t div = i;
                    for (size_t j=0; j< 1e5; ++j){
                        if (N/div % M != 0){
                            ans = max(ans, N/div);
                            break;
                        }
                        div *= i;
                    }
                }
            }
            size_t div = M;
            for (size_t j=0; j< 1e5; ++j){
                if (N/div % M != 0){
                    ans = max(ans, N/div);
                    break;
                }
                div *= M;
            }
            cout << ans << "\n";
        }
    }
}