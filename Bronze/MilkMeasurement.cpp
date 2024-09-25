#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    map<string, long> scoreboard;
    scoreboard["Mildred"] = 7; scoreboard["Elsie"] = 7; scoreboard["Bessie"] = 7;
    map<string, bool> board;
    board["Mildred"] = false; board["Elsie"] = false; board["Bessie"] = false;

    long N; cin >> N;
    vector<tuple<long, string, long>> entries;
    for (size_t i=0; i<N; ++i){
        long day; string name; long diff;
        cin >> day >> name >> diff;
        entries.push_back({day,name,diff});
    }
    sort(entries.begin(), entries.end());
    long count = 0;
    for (auto entry: entries){
        scoreboard[get<1>(entry)] += get<2>(entry);
        long max_score = max(scoreboard["Mildred"], max(scoreboard["Elsie"], scoreboard["Bessie"]));
        bool new_board = false;
        for (auto p: scoreboard){
            if (p.second == max_score){
                if (board[p.first] == false){
                    board[p.first] = true;
                    new_board = true;
                }
            }
            else{
                if (board[p.first] == true){
                    board[p.first] = false;
                    new_board = true;
                }
            }
        }
        if (new_board){
            ++count;
        }
    }
    cout << count;
}