#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<ssize_t> a(N);
        ssize_t maxi = -10e9;
        ssize_t largestDiff = -10e9;
        for (size_t i=0; i<N; ++i){
            cin >> a[i];
            maxi = max(maxi, a[i]);
            largestDiff = max(largestDiff, maxi - a[i]);
        }
        size_t sum = 0;
        size_t x = 0;
        while (sum < largestDiff){
            ++x;
            sum += (1 << (x-1));
        }
        cout << x << "\n";
    }
}