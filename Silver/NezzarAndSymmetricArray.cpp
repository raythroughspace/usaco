#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        set<ssize_t> d;
        for (size_t i=0; i<2*N; ++i){
            ssize_t di; cin >> di;
            if (di < 0){
                d.insert(-di);
            }
            else{
                d.insert(di);
            }
        }
        if (d.size() != N){
            cout << "NO\n";
            continue;
        }
        set<ssize_t> a;
        ssize_t pref = 0; // 2* prefix sum
        ssize_t multiple = 2*N;
        string ans = "YES\n";
        for (auto it = d.rbegin(); it != d.rend(); ++it){
            if ((*it - pref)% multiple == 0 && (*it - pref)> 0){
                a.insert((*it - pref)/multiple);
                pref += 2 * (*it - pref)/multiple;
                multiple -= 2;
            }
            else{
                ans = "NO\n";
            }
        }
        if (a.size() != N){
            ans = "NO\n";
        }
        cout << ans;
    }
}