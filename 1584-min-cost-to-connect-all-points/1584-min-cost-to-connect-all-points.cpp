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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges; 
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + 
                   abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        int sum = 0;

        for(auto edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];
    
            if(dsu.find(u) == dsu.find(v)) continue; // cycle! skip
            dsu.unionByRank(u, v); // union them
            sum += weight; // add to MST cost
            }
        
        return sum;
    }
};