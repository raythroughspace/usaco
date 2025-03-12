#include <bits/stdc++.h>
using namespace std;

bool possible(size_t sum, size_t N, multiset<size_t> a){
    for (size_t i=0; i<N; ++i){
        size_t largest = *(--a.end());
        auto other = a.find(sum-largest);
        if (other == a.end() || other == (--a.end())){
            return false;
        }
        sum = largest;
        a.erase((--a.end()));
        a.erase(other);
    }
    return true;
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        multiset<size_t> a;
        for (size_t i=0; i<2*N; ++i){
            size_t ai; cin >> ai;
            a.insert(ai);
        }
        size_t ans = 0;
        size_t largest = *(--a.end());
        for (auto it = a.begin(); it != (--a.end()); ++it){
            if (possible(largest + *it, N, a)){
                ans = largest + *it;
                cout << "YES\n";
                cout << ans << "\n";
                for (size_t i=0; i<N; ++i){
                    largest = *(--a.end());
                    auto other = a.find(ans-largest);
                    cout << largest << " " << *other << "\n";
                    ans = largest;
                    a.erase((--a.end()));
                    a.erase(other);
                }
                break;
            }
        }
        if (ans == 0){
            // no answer
            cout << "NO\n";
        }
    }
}