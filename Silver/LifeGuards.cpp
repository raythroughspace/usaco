#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<ssize_t,ssize_t>> guards(N);
    for (size_t i=0; i<N; ++i){
        cin >> guards[i].first >> guards[i].second;
    }
    sort(guards.begin(), guards.end());
    size_t minTimeAlone = guards[1].first - guards[0].first;
    ssize_t maxRight = guards[0].second;
    for (size_t i=1; i<N; ++i){
        size_t timeAlone = (guards[i].second - guards[i].first);
        if (maxRight > guards[i].first){
            timeAlone -= (maxRight - guards[i].first);
        }
        if (i < N-1 && guards[i+1].first < guards[i].second){
            if (guards[i+1].first < maxRight){
                minTimeAlone = 0;
            }
            else{
                timeAlone -= (guards[i].second - guards[i+1].first);
            }
        }
        minTimeAlone = min(minTimeAlone, timeAlone);
        maxRight = max(maxRight, guards[i].second);
    }
    ssize_t totalTime = 0;
    ssize_t left = 0, right = 0; 
    for (size_t i=0; i<N; ++i){
        if (guards[i].second > right){
            left = max(right, guards[i].first);
            totalTime += guards[i].second - left;
            right = guards[i].second;
        }
    }
    cout << totalTime - minTimeAlone;

}