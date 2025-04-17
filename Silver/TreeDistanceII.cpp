#include <bits/stdc++.h>
using namespace std;

void dfs(size_t i, const vector<vector<size_t>>& adj, 
vector<bool>& visited, vector<ssize_t>& subtreesz, size_t& Da, size_t depth)
{
    Da += depth;
    visited[i] = true;
    subtreesz[i] = 1; // initialize to 1
    for (const auto j: adj[i]){
        if (!visited[j]){
            dfs(j, adj, visited, subtreesz, Da, depth + 1);
            subtreesz[i] += subtreesz[j];
        }
    }
}

void dfs2(size_t i, const vector<vector<size_t>>& adj, 
vector<bool>& visited, vector<ssize_t>& subtreesz, vector<ssize_t>& distances, size_t parent, size_t N)
{
    visited[i] = true;
    if (i != 1){
        distances[i] = distances[parent] - 2 * subtreesz[i] + N;
    }
    for (const auto j: adj[i]){
        if (!visited[j]){
            dfs2(j, adj, visited, subtreesz, distances, i, N);
        }
    }
}

int main() 
{
	size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<N; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ssize_t> subtreesz(N+1);
    vector<bool> visited(N+1);
    size_t Da = 0;
    dfs(1, adj, visited, subtreesz, Da, 0);
    vector<ssize_t> distances(N+1);
    distances[1] = Da;
    fill(visited.begin(), visited.end(), false);
    dfs2(1, adj, visited, subtreesz, distances, 0, N);
    for (size_t i=1; i<=N; ++i){
        cout << distances[i]<< " ";
    }
}
