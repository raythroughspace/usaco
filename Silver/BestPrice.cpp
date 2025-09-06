#include <bits/stdc++.h>
using namespace std;

pair<bool, size_t> possible(size_t price, size_t N, size_t K, 
    const vector<size_t>& a, const vector<size_t>& b){
        size_t neg = 0;
        size_t earnings = 0;
        for (size_t i=0; i<N; ++i){
            if (price <= b[i] && price > a[i]){
                ++neg;
            }
            if (price <= b[i])
                earnings += price;
        }
        return {neg <= K, earnings};
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,K; cin >> N >> K;
        vector<size_t> aub;
        vector<size_t> a(N);
        for (size_t i=0; i<N; ++i){
            cin >> a[i];
            aub.push_back(a[i]);
        }
        vector<size_t> b(N);
        for (size_t i=0; i<N; ++i){
            cin >> b[i];
            aub.push_back(b[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(aub.begin(), aub.end());
        size_t lo = 0;
        size_t hi = 2*N-1;
        size_t best = 0;
        while (lo <= hi){
            size_t mid = (lo + hi) / 2;
            auto [pos, earnings] = possible(aub[mid], N,K,a,b);
            if (pos){
                best = max(best, earnings);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << best << "\n";
    }
}