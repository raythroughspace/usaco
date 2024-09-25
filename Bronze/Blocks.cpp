#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<string> dice(4);
    for (size_t i=0; i<4; ++i){
        cin >> dice[i];
    }
    for (size_t n=0; n<N; ++n){
        string w; cin >> w;
        map<char, size_t> word;
        for (size_t i=0; i<w.size(); ++i){
            ++word[w[i]];
        }
        map<char, size_t> makeWord;
        bool possible = false;
        for (size_t a=0; a<6; ++a){
            ++makeWord[dice[0][a]];
            for (size_t b=0; b<6; ++b){
                ++makeWord[dice[1][b]];
                for (size_t c=0; c<6; ++c){
                    ++makeWord[dice[2][c]];
                    for (size_t d=0; d<6; ++d){
                        ++makeWord[dice[3][d]];
                        bool matching = true;
                        for (auto c: word){
                            if (c.second > makeWord[c.first]){
                                matching = false;
                            }
                        }
                        if (matching){
                            possible = true;
                        }
                        --makeWord[dice[3][d]];
                    }
                    --makeWord[dice[2][c]];
                }
                --makeWord[dice[1][b]];
            }
            --makeWord[dice[0][a]];
        }
        if (possible){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}