#include <bits/stdc++.h>
using namespace std;

void calc_excitement(size_t N, string S, set<long>& ans){
    size_t block = 1;
    size_t minAns = 0;
    size_t maxAns = 0;
    char start = S[0];
    for (size_t i=1; i<N; ++i){
        ++block;
        if (S[i] == 'F'){
            continue;
        }
        if (S[i] != start){
            maxAns += block-2;
            minAns += (block % 2);
        }
        else{
            maxAns += block-1;
            minAns += ((block-1)%2);
        }
        start = S[i];
        block = 1;
    }
    while (minAns <= maxAns){
        ans.insert(minAns);
        minAns += 2;
    }
}
int main(){
    size_t N; cin >> N;
    string S; cin >> S;
    set<long> ans;
    
    if (S[0] == 'F' && S[N-1] == 'F'){
        vector<pair<char,char>> pairs = {{'B', 'B'}, {'B', 'E'}, {'E', 'B'}, {'E', 'E'}};
        for (auto p: pairs){
            S[0] = p.first; S[N-1] = p.second;
            calc_excitement(N, S, ans);
        }
    }
    else if (S[0] == 'F'){
        vector<char> pos = {'B', 'E'};
        for (auto p: pos){
            S[0] = p;
            calc_excitement(N,S,ans);
        }
    }
    else if (S[N-1] == 'F'){
        vector<char> pos = {'B', 'E'};
        for (auto p: pos){
            S[N-1] = p;
            calc_excitement(N,S,ans);
        }
    }
    else{
        calc_excitement(N,S,ans);
    }
    cout << ans.size() << "\n";
    for (auto e: ans){
        cout << e << "\n";
    }
}