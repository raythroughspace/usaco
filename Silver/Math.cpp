#include <bits/stdc++.h>
using namespace std;
 
int main() {
	size_t N; cin >> N;
    size_t max_ei = 0;
    size_t min_ei = SIZE_MAX;
    size_t curr = N;
    size_t primes_product = 1;
    for (size_t i=2; i<=N; ++i){
        size_t ei = 0;
        if (curr % i == 0)
            primes_product *= i;
        while (curr % i == 0){
            curr = curr / i;
            ++ei;
        }
        max_ei = max(max_ei, ei);
        if (ei != 0)
            min_ei = min(min_ei, ei);
    }
    size_t ans = 0;
    size_t pow = 1;
    for (size_t i=0; i<N; ++i){
        if (pow >= max_ei){
            ans = i+1;
            if (pow == max_ei && max_ei == min_ei)
                --ans;
            break;
        }
        pow *= 2;
    }
    if (N == 1){
        cout << "1 0\n";
    } else {
        cout << primes_product << " "<< ans << "\n";
    }
}