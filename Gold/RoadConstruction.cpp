#include <bits/stdc++.h>
using namespace std;

class DSU {
    private:
        vector<size_t> parents;
        vector<size_t> sizes;
    public:
        explicit DSU(size_t N) : sizes(N, 1), parents(N) {
            for (size_t i=0; i<N; ++i)
                parents[i] = i;
        }
        size_t find(size_t x) const {
            while (x != parents[x])
                x = parents[x];
            return x;
        }
        bool unite(size_t x, size_t y){
            if (find(x) == find(y))
                return false;
            size_t root_x = find(x);
            size_t root_y = find(y);
            if (sizes[root_x] < sizes[root_y])
                swap(root_x, root_y);
            parents[root_y] = parents[root_x];
            sizes[root_x] += sizes[root_y];
            return true;
        }
        size_t getSz(size_t x) const {
            return sizes[find(x)];
        }
};

int main() {
    size_t N,M; cin >> N >> M;
    DSU disjointSets(N+1);
    size_t components = N, largestSz = 1;
    for (size_t i=0; i<M; ++i){
        size_t x,y; cin >> x >> y;
        if (disjointSets.unite(x,y)){
            --components;
            largestSz = max(largestSz, max(disjointSets.getSz(x), disjointSets.getSz(y)));
        } 
        cout << components << " " << largestSz << "\n";
    }
}