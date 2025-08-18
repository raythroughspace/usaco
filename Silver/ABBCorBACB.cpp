#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        string s; cin >> s;
        size_t min_block = SIZE_MAX;
        size_t nAblocks = 0;
        size_t nB = 0;
        for (size_t i=0; i<s.size(); ++i){
            if (s[i] == 'B'){
                ++nB;
            } else {
                ++nAblocks;
                size_t blocksz = 0;
                while (s[i] == 'A'){
                    ++blocksz;
                    ++i;
                }
                --i;
                min_block = min(min_block, blocksz);
            }
        }
        
        if (nB + 1 == nAblocks){
            cout << (s.size() - nB) - min_block << "\n";
        } else {
            cout << s.size() - nB << "\n";
        }
    }
}