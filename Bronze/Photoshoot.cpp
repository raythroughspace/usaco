#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    string S; cin >> S;
    size_t nFlips = 0;
    for (long i= N -1; i>0; i-=2){
        if (nFlips % 2 ==0 && 
        S[i] == 'H' && S[i-1] == 'G'){
            ++nFlips;
        }
        else if (nFlips %2 == 1 &&
        S[i] == 'G' && S[i-1] == 'H'){
            ++nFlips;
        }
    }
    cout << nFlips;
}