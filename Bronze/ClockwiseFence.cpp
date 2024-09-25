#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    for (size_t i=0; i<N; ++i){
        string dir; cin >> dir;
        ssize_t x = 0;
        ssize_t y = 0;
        ssize_t yMax = 0;
        char yMaxDir;
        for (char c: dir){
            if (c == 'W'){
                if (y == yMax){
                    yMaxDir = c;
                }
                --x;
            }
            else if (c == 'E'){
                if (y == yMax){
                    yMaxDir = c;
                }
                ++x;
            }
            else if (c == 'N'){
                ++y;
                yMax = max(yMax, y);
            }
            else{
                --y;
            }
        }
        if (yMaxDir == 'W'){
            cout << "CCW\n";
        }
        else{
            cout << "CW\n";
        }
    }
}