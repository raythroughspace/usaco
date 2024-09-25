#include <bits/stdc++.h>
using namespace std;
// sort interactions by t
// keep track of minK and maxK
//for each cow
//  bool patientZero = false
//  for each K from 0 to T+1
//      make infected list
//      for each interaction:
//          update infected list
//      if infected list == final infected
//          patientZero = true
//          update minK, maxK
//  O(NT^2)
int main(){
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    size_t N,T; cin >> N >> T;
    string inf; cin >> inf;
    vector<tuple<long,long,long>> interactions;
    for (size_t i=0; i<T; ++i){
        long t,x,y; cin >> t >> x >> y;
        interactions.push_back({t,x,y});
    }
    size_t minK,maxK, nP0;
    minK = T; maxK = 0; nP0 = 0;
    inf.insert(0, "0");
    sort(interactions.begin(), interactions.end());
    for (size_t c=1; c<=N; ++c){
        bool patientZero = false;
        for (size_t k=0; k<=T; ++k){
            string infList(N+1, '0');
            infList[c] = '1';
            vector<long> interCounter(N+1, 0);
            interCounter[c] = k;
            for (auto inter: interactions){
                size_t t,x,y; tie(t,x,y) = inter;
                if (infList[x] == '1' && infList[y] == '1'){
                    if (interCounter[x] > 0){
                        --interCounter[x];
                    }
                    if (interCounter[y] > 0){
                        --interCounter[y];
                    }
                }
                else if (infList[x] == '1' && interCounter[x] > 0){
                    --interCounter[x];
                    interCounter[y] = k;
                    infList[y] = '1';
                }
                else if (infList[y] == '1' && interCounter[y] > 0){
                    --interCounter[y];
                    interCounter[x] = k;
                    infList[x] = '1';
                }
            }
            if (infList == inf){
                patientZero = true;
                minK = min(minK, k);
                maxK = max(maxK, k);
            }
        }
        if (patientZero){
            ++nP0;
        }
    }
    if (maxK == T){
        cout << nP0 << " " << minK << " " << "Infinity";
    }
    else{
        cout << nP0 << " " << minK << " " << maxK;
    }

}