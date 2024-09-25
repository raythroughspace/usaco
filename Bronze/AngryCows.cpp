#include <bits/stdc++.h>
using namespace std;
//place bales in set
//construct vector of initial blasts = bale -1, bale, bale + 1
//for each initial position:
//  get l= bales.lower_bound(prevl - t) (first element >= prevl - t)
//  get u = bales.upper_bound(prevu + t) (first element > prevu + t)
//  if (l < prevl) explosion happens at l
//      prevl = l
//  if (u > prevu) explosion happens at u
//      prevu = u
//  if (u==prevu && l==prevl) no new explosions
//      break
//count number of cows between prevu and prevl
int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    size_t N; cin >> N;
    set<long> bales;
    for (size_t i=0; i<N; ++i){
        long x; cin >> x;
        bales.insert(x);
    }
    size_t maxBales = 0;
    for (auto initpos: bales){
        long t = 1;
        long pos = initpos;
        long prevpos = initpos;
        // get lowest bale
        do{
            auto lptr = bales.lower_bound(pos - t); //first element >= prevpos - t
            if (lptr != bales.end()){
                prevpos = pos;
                pos = *lptr;
            }
            ++t;
        }while (prevpos != pos);
        long lo = pos; // lowest bale
        
        pos = initpos;
        prevpos = initpos;
        t = 1;
        //get highest bale
        do {
            auto uptr = bales.upper_bound(pos + t); // first element > prevpos +t
            uptr--;
            prevpos = pos;
            pos = *uptr;
            ++t;
        } while(prevpos != pos);
        long hi = pos;

        size_t nBales = 0;
        for (auto bale: bales){
            if (bale >= lo && bale <= hi){
                ++nBales;
            }
        }
        maxBales = max(nBales, maxBales);
    }
    cout << maxBales;
}