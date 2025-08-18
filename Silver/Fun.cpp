#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        ssize_t N,X; cin >> N >> X;
        size_t count = 0;
        for (ssize_t a=1; a<= N; ++a){
            for (ssize_t b=1; b<= N/a; ++b){
                if (min((N-a*b)/(a+b), X-a-b) > 0){
                    count += min((N-a*b)/(a+b), X-a-b);
                }
            }
        }
        cout << count << "\n";
    }
}