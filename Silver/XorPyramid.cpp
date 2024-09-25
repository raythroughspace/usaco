#include <bits/stdc++.h>
using namespace std;
ssize_t num2factors(size_t n){
    size_t ans = 0;
    while (true){
        if (n % 2 == 0){
            ++ans;
            n /= 2;
        }
        else{
            return ans;
        }
    }
}

int main(){
    size_t N; cin >> N;
    size_t n = N-1;
    vector<size_t> bin2factors(n+1, 0);
    for (size_t k=0; k<n; ++k){
        bin2factors[k+1] = bin2factors[k] + num2factors(n-k) - num2factors(k+1);
    }
    size_t ans = 0;
    for (size_t i=0; i<N; ++i){
        size_t a; cin >> a;
        if (bin2factors[i] == 0){
            ans ^= a;
        }
    }
    cout << ans;
}