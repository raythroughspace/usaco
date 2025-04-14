#include <bits/stdc++.h>
using namespace std;
#define T 1000
#define INF 1e10

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
	ssize_t N,M,C; cin >> N >> M >> C;
    vector<ssize_t> m(N+1);
    vector<vector<ssize_t>> adj(N+1);
    for (size_t i=1; i<=N; ++i)
        cin >> m[i];

    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<vector<ssize_t>> x(T+1, vector<ssize_t>(N+1, -INF));
    x[0][1] = 0;
    for (size_t t=1; t<= T; ++t){
        for (size_t i=1; i<=N; ++i){
            for (const auto j: adj[i]){
                x[t][i] = max<ssize_t>(x[t-1][j] + m[j], x[t][i]);
            }
        }
    }
    ssize_t ans = 0;
    for (size_t t = 0; t<=T; ++t){
        ans = max<ssize_t>(x[t][1] - C*t*t, ans);
    }
    cout << ans;
}
