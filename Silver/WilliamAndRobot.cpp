#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<size_t> A(N);
    size_t totalSum = 0;
    for (size_t i=0; i<N; ++i){
        cin >> A[i];
        totalSum += A[i];
    }
    priority_queue<size_t, vector<size_t>, greater<size_t>> pq;
    size_t robotSum = 0;
    for (size_t i=0; i<N; i+=2){
        pq.push(A[i]);
        pq.push(A[i+1]);
        robotSum += pq.top();
        pq.pop();
    }
    cout << totalSum - robotSum;

}