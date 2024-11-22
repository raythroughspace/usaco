#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N; cin >> N;
    vector<pair<size_t,size_t>> times(N); //depart, arrival
    for (size_t i=0; i<N; ++i){
        cin >> times[i].second >> times[i].first;
    }
    sort(times.begin(), times.end());
    set<size_t> rooms; rooms.insert(times[0].first);
    cout << "1 ";
    // room of departure times, if new arrival <= all departures, add new room, 
    // otherwise, find new arrival > largest departure possible, remove largest departure and insert new departure
    for (size_t i=1; i<N; ++i){
        if (times[i].second <= *rooms.begin()){ // use new room
            cout << rooms.size() + 1 << " ";
        }
        else{
            auto ptr = rooms.upper_bound(times[i].second);
            cout << distance(rooms.begin(), ptr) - 1 << " ";
            --ptr;
            rooms.erase(*ptr);
        }
        rooms.insert(times[i].first);
    }
}