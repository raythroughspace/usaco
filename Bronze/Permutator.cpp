#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long k = 1; k<=n; ++k){
        cin >> a[k-1];
        a[k-1] = (n-k+1)*k*a[k-1];
    }
    for (long long k = 1; k<=n; ++k){
        cin >> b[k-1];
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    long long sum = 0;
    for (long k=0; k<n; ++k){
        sum += a[k]*b[k];
    }
    cout << sum;
}