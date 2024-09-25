#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t K,N; cin >> K >> N;
    vector<vector<char>> adj(N, vector<char>(N, '?'));
    map<string, size_t> name2id;
    for (size_t i=0; i<N; ++i){
        string name; cin >> name;
        name2id[name] = i;
    }
    for (size_t i=0; i<K; ++i){
        vector<vector<string>> equals;
        string name; cin >> name;
        equals.push_back({name});
        for (size_t j=1; j<N; ++j){
            string next; cin >> next;
            if (next > name){
                equals[equals.size() - 1].push_back(next);
            }
            else{
                equals.push_back({next});
            }
            name = next;
        }

        for (auto v1: equals){
            for (auto v2: equals){
                for (auto n1: v1){
                    for (auto n2: v2){
                        if (v1 != v2){
                            adj[name2id[n1]][name2id[n2]] = '1';
                            adj[name2id[n2]][name2id[n1]] = '0';

                        }
                        else{
                            adj[name2id[n1]][name2id[n1]] = 'B';
                        }
                    }
                }
            }
        }

    }
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            cout << adj[i][j];
        }
        cout << "\n";
    }
}