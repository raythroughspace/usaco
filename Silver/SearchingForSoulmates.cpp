#include <bits/stdc++.h>
using namespace std;
size_t going_up(size_t a, size_t b){
    size_t num2factors = 0;
    size_t ans = 0;
    while (a * 2 < b){
        ++ans;
        ++num2factors;
        a *= 2;
    }
    for (ssize_t i=num2factors; i>=0; --i){
        ans += ((b-a)/ (1 << num2factors));
        b -= ((b-a)/ (1 << num2factors)) * (1 << num2factors);
        --num2factors;
    }
    return ans;
}
int main(){
    size_t N; cin >> N;
    for (size_t n=0; n<N; ++n){
        size_t a,b; cin >> a >> b;
        size_t ans = 0;
        size_t best = LONG_LONG_MAX;
        vector<pair<size_t,size_t>> as;
        do{
            if (a <=b){
                as.push_back({a, ans});
            }
            if (a % 2 != 0){
                ++ans;
                ++a;
            }
            a/=2;
            ++ans;
        } while (a!=1);

        for (auto val: as){
            best = min(best, val.second + going_up(val.first, b));
        }
        cout << best << "\n";
    }
}