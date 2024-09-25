#include <bits/stdc++.h>
using namespace std;

int main(){
    // sort cows by increasing milk
    // sort milk stores by decreasing prices, {}
    // sort rent by decreasing prices
    // suffix[i] = max price obtained by selling milk from cows i+1 ... 
    //              for each cow in reverse order:
    //                      price += gallons* price
    //                      milk[idx] -= gallons    
    // prefix[i] = max price obtained by renting cows up to i = prefix sum of rent prices
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    size_t N,M,R; cin >> N >> M >> R;
    vector<size_t> cows(N);
    vector<pair<size_t, ssize_t>> milkStores(M); //price, gallons
    vector<size_t> rent(R+1);
    for (size_t i=0; i<N; ++i){
        cin >> cows[i];
    }
    for (size_t i=0; i<M; ++i){
        cin >> milkStores[i].second >> milkStores[i].first;
    }
    for (size_t i=1; i<=R; ++i){
        cin >> rent[i];
    }
    sort(cows.begin(), cows.end());
    sort(milkStores.rbegin(), milkStores.rend());
    rent[0] = SIZE_MAX;
    sort(rent.rbegin(), rent.rend());
    rent[0] = 0;
    for (size_t i=1; i<=R; ++i){
        rent[i] += rent[i-1];
    }
    // suffix[i] = max price obtained by selling milk from cows i ... 
    //              for each cow in reverse order:
    //                      price += gallons* price
    //                      milk[idx] -= gallons 
    vector<size_t> suffix(N); 
    size_t price = 0;
    size_t idx = 0;
    for (ssize_t i=N-1; i>=0; --i){
        ssize_t gallons = cows[i];
        while (gallons > 0 && idx < M){
            if (gallons <= milkStores[idx].second){
                milkStores[idx].second -= gallons;
                price += gallons * milkStores[idx].first;
                gallons = 0;
            }
            else{
                price += milkStores[idx].second * milkStores[idx].first;
                gallons -= milkStores[idx].second;
                ++idx;
            }
        }
        suffix[i] = price;
    }

    // for each i = 0 to min(N,R) cows, calculate profit by renting i cows and selling milk for
    // the rest of cows = rent[i] + suffix[i]
    size_t maxProfit = suffix[0];
    for (size_t i=1; i<=min(N,R); ++i){
        maxProfit = max(rent[i] + suffix[i], maxProfit);
    }
    cout << maxProfit;
}