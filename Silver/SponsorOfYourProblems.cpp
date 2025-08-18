#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        string l,r; cin >> l >> r;
        size_t pref = 0;
        for (size_t i=0; i< l.size(); ++i){
            if (l[i] != r[i])
                break;
            ++pref;
        }
        if (pref == l.size() || r[pref] > l[pref] + 1){
            cout << 2 * pref << "\n";
            continue;
        }
        size_t lo = 1;
        // try lower digit
        for (size_t i=pref + 1; i<l.size(); ++i){
            if (l[i] == '9'){ // must pick 9, next digit must be >= l[i+1]
                ++lo;
                if (r[i] == '9')
                    ++lo;
            }
            else if (l[i] == '8' && r[i] == '9'){
                ++lo; // pick 9 and the rest can be anyting
                break;
            }
            else{
                break;
            }
        }
        // try higher digit
        size_t hi = 1;
        for (size_t i=pref + 1; i<r.size(); ++i){
            if (r[i] == '0'){
                ++hi;
                if (l[i] == '0'){
                    ++hi;
                }
            }
            else if (r[i] == '1' && l[i] == '0'){
                ++hi;
                break;
            }
            else {
                break;
            }
        }
        cout << 2*pref + min(hi, lo) << "\n";

    }
}