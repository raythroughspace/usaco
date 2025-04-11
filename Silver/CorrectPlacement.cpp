#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<size_t, size_t>& p1, const pair<size_t,size_t>& p2){
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<pair<size_t,size_t>> people1(N);
        map<pair<size_t,size_t>, size_t> person2idx;
        for (size_t i=0; i<N; ++i){
            cin >> people1[i].first >> people1[i].second;
            person2idx[people1[i]] = i;
        }
        vector<pair<size_t,size_t>> people2(people1);

        // sort people1 by h, minwpref = tuples {minsofar of w, idx of person}
        sort(people1.begin(), people1.end()); // sort by h
        vector<pair<size_t,size_t>> minwpref(N); minwpref[0] = {people1[0].second, person2idx[people1[0]]};
        for (size_t i=1; i<N; ++i){
            if (people1[i].second < minwpref[i-1].first){
                // w < minsofar for w
                minwpref[i] = {people1[i].second, person2idx[people1[i]]};
            }
        }

        // sort people2 by w, minhpref = tuples {minsofar of h, idx of person}
        sort(people2.begin(), people2.end(), compare);
        vector<pair<size_t,size_t>> minhpref(N); minhpref[0] = {people2[0].first, person2idx[people2[0]]};
        for (size_t i=1; i<N; ++i){
            if (people2[i].first < minhpref[i-1].first){
                // h < minsofar for h
                minhpref[i] = {people2[i].first, person2idx[people2[i]]};
            }
        }
        vector<ssize_t> answers(N);
        for (size_t i=0; i<N; ++i){
            // find first hj s.t hi > hj
            pair<size_t,size_t> p ={people1[i].first - 1, SIZE_MAX};
            auto it = upper_bound(people1.begin(), people1.end(), p); // result will be first {person1[i].first, ___}
            if (!(it == people1.begin())){
                --it; // first person j with hi > hj
                size_t j = (it - people1.begin());
                if (minwpref[j].first < people1[i].second && people1[i].first > it->first){
                    // wj < wi, found j in front of i
                    answers[person2idx[people1[i]]] = minwpref[j].second + 1;
                }
            }
            // find first wj s.t wj < hi
            p = {SIZE_MAX, people2[i].first - 1};
            it = upper_bound(people2.begin(), people2.end(), p, compare); //first {__, people2[i].first}
            if (!(it == people2.begin())){
                --it;
                size_t j = (it - people2.begin());
                if (minhpref[j].first < people2[i].second && people2[i].first > it->second){
                    answers[person2idx[people2[i]]] = minhpref[j].second + 1;
                }
            }
        }
        for (size_t i=0; i<N; ++i){
            if (answers[i]){
                cout << answers[i] << " ";
            }
            else{
                cout << "-1 ";
            }
        }
        cout << "\n";
    }
}