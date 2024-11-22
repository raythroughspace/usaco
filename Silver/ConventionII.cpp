#include <bits/stdc++.h>
using namespace std;

struct compare{
bool operator()(const tuple<size_t,size_t,size_t> &a, const tuple<size_t,size_t,size_t> &b){
    return get<2>(a) > get<2>(b);
}
};
int main(){
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    //sort cows according to time they arrive
    //make pq waiting and add cows that are waiting (based on seniority)
    // keep processing cows and add cows to waiting when time gets incremented
    size_t N; cin >> N;
    vector<tuple<size_t,size_t,size_t>> cows(N);
    for (size_t i=0; i<N; ++i){
        size_t a,t; cin >> a >> t;
        cows[i] = {a,t,i};
    }
    sort(cows.begin(), cows.end());
    priority_queue<tuple<size_t,size_t,size_t>, vector<tuple<size_t,size_t,size_t>>, compare> waiting;
    size_t ans = 0; // first cow does not wait
    size_t time = get<0>(cows[0]) + get<1>(cows[0]);
    size_t i = 1;
    while (i<N || !waiting.empty()){
        if (i<N && time >= get<0>(cows[i])){
            //cows are arriving as some other cow is still eating
            waiting.push(cows[i]);
            ++i;
        }
        else if (!waiting.empty()){
            // process cow
            size_t a,t,seniority;
            tie(a,t,seniority) = waiting.top();
            ans = max(ans, time - a);
            time += t;
            waiting.pop();
        }
        else{
            //no cow is eating and no cow waiting
            time = get<0>(cows[i]) + get<1>(cows[i]); //cow i has no wait time
            ++i;
        }
    }
    cout << ans;
    
}