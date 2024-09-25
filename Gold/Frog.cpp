#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<ssize_t> heights(N);
    for (size_t i=0; i<N; ++i){
        cin >> heights[i];
    }
    vector<size_t> cost(N);
    cost[N-1] = 0;
    for (ssize_t i= N-2; i>=0; --i){
        cost[i] = cost[i+1] + abs(heights[i] - heights[i+1]);
        if (i != N-2){
            cost[i] = min(cost[i], cost[i+2] + abs(heights[i] - heights[i+2]));
        }
    }
    cout << cost[0];
}