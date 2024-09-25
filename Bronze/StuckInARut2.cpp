#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<pair<ssize_t, ssize_t>> east; // (y,x)
    vector<pair<ssize_t, ssize_t>> north; // (x,y)
    map<size_t, pair<ssize_t,ssize_t>> idx2pt;
    for (size_t i=0; i<N; ++i){
        char dir; ssize_t x,y; cin >> dir >> x >> y;
        if (dir == 'E'){
            east.push_back({y,x});
        }
        else{
            north.push_back({x,y});
        }
        idx2pt[i] = {x,y};
    }
    sort(east.begin(), east.end());
    sort(north.begin(), north.end());
    vector<ssize_t> eastStop(east.size(), -1);
    vector<ssize_t> northStop(north.size(), -1);
    for (size_t i=0; i<north.size(); ++i){
        for (size_t j=0; j<east.size(); ++j){
            if (northStop[i] != -1){
                break; // stopped
            }
            if (eastStop[j] != -1){
                continue;
            }
            ssize_t x1,x2,y1,y2;
            x1 = north[i].first; y1 = north[i].second;
            x2 = east[j].second; y2 = east[j].first;
            if (x2 > x1 || y1 > y2){
                continue;
            }
            if (x1 - x2 > y2 - y1){
                eastStop[j] = x1 - x2;
            }
            else if (y2 - y1 > x1 - x2){
                northStop[i] = y2 - y1;
            }
        }
    }
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<north.size(); ++j){
            if (north[j] == idx2pt[i]){
                if (northStop[j] == -1){
                    cout << "Infinity\n";
                }
                else{
                    cout << northStop[j] << "\n";
                }
            }
        }
        for (size_t j=0; j<east.size(); ++j){
            if (east[j].second == idx2pt[i].first
            && east[j].first == idx2pt[i].second){
                if (eastStop[j] == -1){
                    cout << "Infinity\n";
                }
                else{
                    cout << eastStop[j] << "\n";
                }
            }
        }
    }


}