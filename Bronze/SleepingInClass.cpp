#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t vec_sum = 0; 
        size_t N; cin >> N;
        vector<size_t> log;
        for (size_t i=0; i<N; ++i){
            size_t entry; cin >> entry;
            log.push_back(entry);
            vec_sum += entry;
        }
        vector<size_t> pos_equal; pos_equal.push_back(vec_sum); //list of possible end results
        for (size_t i=2; i<= vec_sum; ++i){
            if (vec_sum % i == 0){
                pos_equal.push_back(vec_sum/i);
            }
        }
        size_t ans = N;
        for (auto end: pos_equal){
            bool possible = true;
            size_t num_ops = 0;
            vector<size_t> log_copy(log);
            for (size_t i=0; i<N-1; ++i){
                if (log_copy[i]> end){
                    possible = false;
                    break;
                }
                else if (log_copy[i] < end){
                    log_copy[i+1] += log_copy[i];
                    ++num_ops;
                }
            }
            if (log_copy[N-1] == end && possible){
                ans = min(num_ops, ans);
            }
        }
        cout << ans << "\n";
    }
}