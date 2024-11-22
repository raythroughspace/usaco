#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    size_t N; cin >> N;
    vector<ssize_t> locations(N);
    for (size_t i=0; i<N; ++i){
        cin >> locations[i];
    }
    sort(locations.begin(), locations.end());
    vector<ssize_t> gaps(N-1);
    for (size_t i=1; i<N; ++i){
        gaps[i-1] = locations[i] - locations[i-1];
    }
    size_t minimum = LONG_LONG_MAX;
    //exception cases for min
    if (locations[N-2] - locations[0] == N-2 && locations[N-1] - locations[N-2] > 2){
        minimum = 2;
    }
    else if (locations[N-1] - locations[1] == N-2 && locations[1] - locations[0] > 2){
        minimum = 2;
    }
    else{
        size_t hi =0;
        size_t count = 0;
        for (size_t i=0; i<N; ++i){
            while (hi < N && locations[hi] - locations[i] < N){
                ++hi;
                ++count;
            }
            minimum = min(minimum, N-count);
            --count;
        }
    }
    size_t maximum = max(gaps[0] -1, gaps[N-2] -1);
    for (size_t i=1; i<N-2; ++i){
        maximum += (gaps[i] - 1);
    }
    cout << minimum << "\n" << maximum;
}