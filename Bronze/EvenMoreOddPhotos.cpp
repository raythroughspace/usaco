#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    size_t odds = 0;
    size_t evens = 0;
    for (size_t i=0; i<N; ++i){
        size_t ID; cin >> ID;
        if (ID %2 == 0){
            ++evens;
        }
        else{
            ++odds;
        }
    }
    size_t ans = 0;
    if (evens > odds){
        ans = 2*odds + 1;
    }
    else{
        size_t r = (odds - evens)%3;
        size_t p = (odds - evens)/3;
        ans = 2*evens + 2*p;
        if (r == 1){
            --ans;
        }
        else if (r==2){
            ++ans;
        }
    }
    cout << ans;
}