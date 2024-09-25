#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    long K,N; cin >> K >> N;
    for (size_t i=0; i<N; ++i){
        long X; cin >> X;
        long d = K;
        long speed = 0;
        long time = 0;
        while (d > 0){
            if (speed < X){
                ++speed;
            }
            else{
                long k = speed - X;
                if (d > (k+1)*X + ((k+1)*(k+2))/2){
                    ++speed;
                }
                else if (d > k*X + k*(k+1)/2){
                }
                else{
                    --speed;
                }
            }
            d-=speed;
            ++time;
        }
        cout << time << "\n";
    }
}