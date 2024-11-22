#include <bits/stdc++.h>
using namespace std;

int main(){

    size_t N,M; cin >> N >> M;
    vector<vector<char>> grid(N+1, vector<char>(M+1));
    pair<size_t,size_t> start, end;
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=M; ++j){
            cin >> grid[i][j];
            if (grid[i][j] == 'A'){
                start = {i,j};
            }
            else if (grid[i][j] == 'B'){
                end = {i,j};
            }
        }
    }
    
   vector<vector<bool>> visited(N+1, vector<bool>(M+1));
   visited[start.first][start.second] = true;
   queue<pair<size_t,size_t>> process; process.push(start);
   vector<vector<char>> parents(N+1, vector<char>(M+1, 'X'));
   while (!process.empty()){
        auto [i, j] = process.front();
        process.pop();
        if (i-1 >= 1 && !visited[i-1][j] && grid[i-1][j] != '#'){
            visited[i-1][j] = true;
            parents[i-1][j] = 'U';
            process.push({i-1, j});
        }
        if (j-1 >= 1 && !visited[i][j-1] && grid[i][j-1] != '#'){
            visited[i][j-1] = true;
            parents[i][j-1] = 'L';
            process.push({i, j-1});
        }
        if (j+1 <= M && !visited[i][j+1] && grid[i][j+1] != '#'){
            visited[i][j+1] = true;
            parents[i][j+1] = 'R';
            process.push({i, j+1});
        }
        if (i+1 <= N && !visited[i+1][j] && grid[i+1][j] != '#'){
            visited[i+1][j] = true;
            parents[i+1][j] = 'D';
            process.push({i+1, j});
        }
   }
   auto [i, j] = end;
   if (parents[i][j] =='X'){
    cout << "NO";
   }
   else{
    cout << "YES\n";
    stack<char> route;
    while (parents[i][j] != 'X'){
        route.push(parents[i][j]);
        switch (route.top()){
            case 'R':
                j = j-1;
                break;
            case 'L':
                j = j+1;
                break;
            case 'U':
                i = i+1;
                break;
            case 'D':
                i = i-1;
                break;
        }
    }
    cout << route.size() << "\n";
    while (!route.empty()){
        cout << route.top();
        route.pop();
    }
   }

    
}