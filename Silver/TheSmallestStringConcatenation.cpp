#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<string> a(N);
    for (size_t i=0; i<N; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](string x, string y){
        string tmp1(x);
        tmp1.append(y);
        y.append(x);
        return tmp1 < y;
    });
    string ans = "";
    for (size_t i=0; i<N; ++i){
        ans.append(a[i]);
    }
    cout << ans;
}