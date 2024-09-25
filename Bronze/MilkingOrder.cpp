#include <bits/stdc++.h>
using namespace std;

bool checkPositions(vector<size_t>& posCopy, vector<size_t>& order){
    size_t idx = 0;
    size_t N = posCopy.size();
    for (auto e: order){
        while (posCopy[idx] != e){
            idx++;
            if (idx == N){
                return false;
            }
        }
    }
    return true;
}
int main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    size_t N,M,K; cin >> N >> M >> K;
    vector<size_t> order(M);
    vector<size_t> pos(N, 0);
    for (size_t i=0; i<M; ++i){
        cin >> order[i];
    }
    set<size_t> posCows;
    for (size_t i=0; i<K; ++i){
        size_t a,b; cin >> a >> b;
        pos[b-1] = a;
        posCows.insert(a);
    }
    // cow number 1 is already forced into position
    if (posCows.count(1)){
        for (size_t i=0; i<N; ++i){
            if (pos[i] == 1){
                cout << i+1;
                break;
            }
        }
    }
    else{
        for (size_t i=0; i<N; ++i){
            if (pos[i] != 0){ //position i is already occupied
                continue;
            }
            vector<size_t> posCopy(pos);
            posCopy[i] = 1; // place cow 1 in position i

            for (auto cow: order){ //for each cow in order, place them as early as possible
                if (posCows.count(cow) || cow == 1){
                    continue; //cow is already positioned
                }
                for (size_t j=0; j<N; ++j){
                    if (posCopy[j] == 0){
                        posCopy[j] = cow;
                        break;
                    }
                }
            }

            if (checkPositions(posCopy, order)){
                cout << i+1;
                break;
            }
        }
    }
}