#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    // at each step, find largest profit[i] with capital[i] <= w
    // sort array by (capital, profit), loop through, adding profit to max heap when capital <= w
    size_t N = profits.size();
    vector<pair<size_t,size_t>> pairs(N);
    for (size_t i=0; i<N; ++i){;
        pairs[i] = {capital[i], profits[i]};
    }
    sort(pairs.begin(), pairs.end());
    priority_queue<size_t> profitspq;
    size_t i=0;
    while (i<N){
        auto [c,p] = pairs[i];
        if (k == 0 || ((c > w) && profitspq.size() == 0))
            break;
            
        if (c <= w){
            profitspq.push(p);
            ++i;
        }
        else{
            // must increase w
            --k;
            w += profitspq.top();
            profitspq.pop();
        }
    }
    while (k>0 && profitspq.size() > 0){
        --k;
        w += profitspq.top();
        profitspq.pop();
    }
    return w;
}

int main(){
    vector<int> profits{1,2,3};
    vector<int> capital{1,1,2};
    cout << findMaximizedCapital(1, 0, profits, capital);
}