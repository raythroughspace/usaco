#include <bits/stdc++.h>
using namespace std;
struct Friend {
    size_t h;
    size_t w;
    size_t idx;
};

bool compare(const Friend f1, const Friend f2){
    
}

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N; cin >> N;
        vector<Friend> friends(N);
        for (size_t i=0; i<N; ++i){
            cin >> friends[i].h >> friends[i].w;
            friends[i].idx = i;
        }
        vector<Friend> 
    }
}