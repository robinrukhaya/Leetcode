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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i = 0; i < n;i++) {
            for (int j = 0;j<n;j++) {
                if(isConnected[i][j] == 1) {
                    dsu.unionByRank(i,j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i <n;i++) {
        if(dsu.find(i) == i) count++;
        }
        return count;
    }
};