#include <bits/stdc++.h>
using namespace std;
ssize_t A_beats_B(const vector<size_t>& dieA, const vector<size_t>& dieB){
    ssize_t score = 0;
    for (size_t i=0; i<4; ++i){
        for (size_t j=0; j<4; ++j){
            if (dieA[i] > dieB[j]){
                ++score;
            }
            else if (dieA[i] < dieB[j]){
                --score;
            }
        }
    }
    return score;
}
int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        vector<size_t> dieA(4);
        vector<size_t> dieB(4);
        for (size_t i=0; i<4; ++i){
            cin >> dieA[i];
        }
        for (size_t i=0; i<4; ++i){
            cin >> dieB[i];
        }
        if (A_beats_B(dieA, dieB) == 0){
            cout << "no\n";
            continue;
        }
        else if (A_beats_B(dieA, dieB) < 0){
            dieA.swap(dieB); // swap naming so dieA always beats dieB
        }
        vector<size_t> dieC(4);
        bool possible = false;
        for (size_t a=1; a<=10; ++a){
            dieC[0] = a;
            for (size_t b=1; b<=10; ++b){
                dieC[1] = b;
                for (size_t c=1; c<=10; ++c){
                    dieC[2] = c;
                    for (size_t d=1; d<=10; ++d){
                        dieC[3] = d;
                        if (A_beats_B(dieC, dieA) > 0 && A_beats_B(dieB, dieC) > 0){
                            possible = true;
                        }
                    }
                }
            }
        }
        if (possible){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
}