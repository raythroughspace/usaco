#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t x,y; cin >> x >> y;
        if (x == y){
            cout << -1 << "\n";
            continue;
        } else if (x < y){
            swap(x,y);
        }
        size_t pow = 1;
        while (pow <= x){
            pow *= 2;
        }
        cout << pow - x << "\n";
    }
}