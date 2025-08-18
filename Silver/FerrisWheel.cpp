#include <bits/stdc++.h>
using namespace std;

int main() {
	size_t N,X; cin >> N >> X;
    vector<size_t> p(N);
    for (size_t i=0; i<N; ++i)
        cin >> p[i];

    sort(p.begin(), p.end());
    size_t sec = 0;
    size_t ans = 0;
    vector<bool> usedp(N);
    for (ssize_t i=N-1; i>=0; --i){
        if (usedp[i])
            continue;
        ++ans;
        usedp[i] = true;

        if (sec < i && p[i] + p[sec] <= X){
            usedp[sec] = true;
            ++sec;
        }

    }
    cout << ans;
}
