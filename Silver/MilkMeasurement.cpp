#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    size_t N, G; cin >> N >> G;
    set<pair<size_t, size_t>> production; // (milk output, cow #)
    map<size_t, size_t> cow2product; // cow2product[cow #] = milk output
    map<size_t,size_t> product2count; // product2count[milk output] = # of cows with milk output
    product2count[G] = N;
    //production.insert({G, 0}); 
    //cow2product[0] = G;
    // if all cows tracked produce less than G, then max milk output will be G
    vector<tuple<ssize_t,ssize_t,ssize_t>> log(N);
    for (size_t i=0; i<N; ++i){
        ssize_t a,b,c; cin >> a >> b >> c;
        log[i] = {a,b,c};
        cow2product[b] = G;
        production.insert({G, b});
    }
    size_t ans = 0;
    size_t largest = G;
    sort(log.begin(), log.end());
    for (size_t i=0; i<N; ++i){
        ssize_t a,b,c; tie(a,b,c) = log[i];

        pair<size_t,size_t> product = {cow2product[b], b};
        bool wasTop = cow2product[b] == production.rbegin()->first;
        size_t prevCount = product2count[cow2product[b]];

        assert(production.erase(product) == 1);
        --product2count[product.first];

        cow2product[b] = product.first + c;
        production.insert({product.first + c, b});
        ++product2count[product.first + c];

        largest = max(largest, production.rbegin()->first);
        bool isTop = largest == cow2product[b];

        if (wasTop){
            if (isTop && prevCount == product2count[largest]){
                continue;
            }
            ++ans;
        }
        else if (isTop){
            ++ans;
        }

    }

    cout << ans;

}