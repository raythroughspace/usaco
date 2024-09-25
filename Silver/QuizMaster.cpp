#include <bits/stdc++.h>
using namespace std;
bool can_exclude(size_t idx, vector<pair<size_t,unordered_set<size_t>>>& students, 
unordered_map<size_t,size_t>& mastery){
    for (auto topic: students[idx].second){
        if (mastery[topic] <= 1){
            return false;
        }
    } 
    return true;
}

void exclude(size_t idx, vector<pair<size_t,unordered_set<size_t>>>& students, 
unordered_map<size_t,size_t>& mastery){
    for (auto topic: students[idx].second){
        --mastery[topic];
    }
}

void include(size_t idx, vector<pair<size_t,unordered_set<size_t>>>& students, 
unordered_map<size_t,size_t>& mastery){
    for (auto topic: students[idx].second){
        ++mastery[topic];
    }
}

int main(){
    // for each topic, keep track of how many students mastered it
    // for each student, keep track of all topics mastered (root n time) 
    // sort students, two pointer, move high pointer as left as possible
    // then move right pointer right
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,M; cin >> N >> M;
        vector<pair<size_t, unordered_set<size_t>>> students(N);  //intelligence -> divisors/topics mastered
        unordered_map<size_t, size_t> mastery; //topic -> number students
        for (size_t i=0; i<N; ++i){
            size_t a; cin >> a;
            for (size_t j=1; j<=M; ++j){ //sqrt n times
                if (a % j == 0){
                    if (a/j < j){
                        break; // already got all divisors
                    }
                    students[i].second.insert(j);
                    ++mastery[j];
                    if (a/j <= M && a/j != j){
                        students[i].second.insert(a/j);
                        ++mastery[a/j];
                    }
                }
            }
            assert(students[i].second.size() != 0);
            students[i].first = a;
        }
        bool ans = true;
        for (size_t i=1; i<=M; ++i){
            if (mastery[i] == 0){
                ans = false;
            }
        }
        if (!ans){
            cout << "-1\n";
            continue;
        }
        sort(students.begin(), students.end(), [](pair<size_t,unordered_set<size_t>>& a, 
        pair<size_t, unordered_set<size_t>>& b){
            return a.first < b.first;
        }); //sort by intelligence
        size_t minRange = LONG_LONG_MAX;
        ssize_t hi = N-1;
        ssize_t lo = 0;
        while (can_exclude(hi, students, mastery) && hi >=0){
            exclude(hi, students, mastery);
            --hi;
        }
        minRange = min(minRange, students[hi].first - students[lo].first);
        while (lo<=hi){
            if (can_exclude(lo, students, mastery)){
                exclude(lo, students, mastery);
                ++lo;
            }
            else if (hi < N){ // can't exclude lo right now, need to make hi higher
                include(hi, students, mastery);
                ++hi;
            }
            else{
                break;
            }
            minRange = min(minRange, students[hi].first - students[lo].first);
        }
        cout << minRange << "\n";
    }

}