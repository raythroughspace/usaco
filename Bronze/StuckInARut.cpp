#include <bits/stdc++.h>
using namespace std;
bool compare2nd(pair<long,long> p1, pair<long,long> p2){
    return p1.second < p2.second;
}
int main(){
    size_t N; cin >> N;
    map<long, pair<long,long>> idx2cow; // keep order of cows
    map<pair<long,long>, long> cow2stop; // how many patches of grass each cow eats
    vector<pair<long,long>> east;
    vector<pair<long,long>> north;
    for (size_t i=0; i<N; ++i){
        char dir; cin >> dir;
        size_t a,b; cin >> a >> b;
        if (dir == 'E'){
            east.push_back({a,b});
        }
        else{
            north.push_back({a,b});
        }
        idx2cow[i] = {a,b};
        cow2stop[{a,b}] = -1;
    }
    sort(east.begin(), east.end(), compare2nd);
    sort(north.begin(), north.end());
    for (auto cow1: east){
        for (auto cow2: north){
            if (cow2stop[cow2] != -1 || cow2stop[cow1] != -1){
                continue; //one of the cows was stopped already
            }
            long x1 = cow1.first;
            long x2 = cow2.first;
            long y1 = cow1.second;
            long y2 = cow2.second;
            if (x2 > x1 && y2 < y1){
                if (y1 - y2 < x2 - x1){
                    cow2stop[cow1] = x2 - x1;
                }
                else if (y1 - y2 > x2 - x1){
                    cow2stop[cow2] = y1 - y2;
                }
            }
        }
    }
    for (size_t i=0; i<N; ++i){
        if (cow2stop[idx2cow[i]] == -1){
            cout << "Infinity" << "\n";
        }
        else{
            cout << cow2stop[idx2cow[i]] << "\n";
        }
    }
}