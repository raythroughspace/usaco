#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<size_t> adj(N+1);
    for (size_t i=1; i<=N; ++i){
        adj[i] = i;
    }
    long A1,A2; cin >> A1 >> A2;
    long B1,B2; cin >> B1 >> B2;
    for (long i=0; i<= A2 - A1; ++i){
        adj[A1 + i] = A2 - i;
    }
    vector<size_t> adj_copy(adj);
    for (long i=0; i<= B2 - B1; ++i){
        adj[B1 + i] = adj_copy[B2 - i];
    }
    for (size_t i=1; i<=N; ++i){
        vector<size_t> cycle; cycle.push_back(i);
        size_t curr = adj[i];
        while (curr != i){
            cycle.push_back(curr);
            curr = adj[curr];
        }
        size_t remain = K % cycle.size();
        cout << cycle[remain] << "\n";
    }
}