class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionByRank(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu(20002);
        for(auto stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;
            dsu.unionByRank(row,col);
        }
        set<int> uniqueRoots;

        for(auto stone : stones) {
            uniqueRoots.insert(dsu.find(stone[0]));
        }
        return stones.size()-uniqueRoots.size();

    }
};