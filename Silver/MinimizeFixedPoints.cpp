#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    unordered_set<size_t> primes;
    for (size_t i=2; i<1e5; ++i){
        bool isprime = true;
        for (size_t j=2; j<i; ++j){
            if (j * j > i)
                break;
            if (i % j == 0)
                isprime = false;
        }
        if (isprime)
            primes.insert(i);
    }
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<size_t> ans; ans.push_back(1);
        for (size_t i=2; i<=N; ++i){
            if (primes.count(i)){
                ans.push_back(i);
            } else if (i % 2 == 0 && primes.count(i/2)){
                ans.push_back(i/2);
                ans[i/2 - 1] = i;
            } else {
                for (size_t j=2; j<i; ++j){
                    if (i % j == 0){
                        ans.push_back(ans[i/j - 1]); // gcd(ans[i/j - 1], i/j) > 1, so gcd(i, ans[i/j - 1]) > 1
                        ans[i/j - 1] = i;
                        break;
                    }
                }
            }
        }
        for (const auto& el: ans){
            cout << el << " ";
        }
        cout << "\n";
    }
}