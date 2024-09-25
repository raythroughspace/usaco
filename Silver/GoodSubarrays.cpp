#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        string S; cin >> S;
        vector<ssize_t> prefix(N+1, 0);
        map<ssize_t, size_t> count;
        count[0] = 1;
        size_t ans = 0;
        for (size_t i=1; i<=N; ++i){
            ssize_t a = S[i-1] - '1';
            prefix[i] = prefix[i-1] + a;
            ans += count[prefix[i]];
            ++count[prefix[i]];
        }
        cout << ans << "\n";
    }
    
}