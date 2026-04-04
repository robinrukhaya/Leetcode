// User function Template for C++

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> tin(V);
        vector<int> low(V);
        vector<bool> vis(V, false);
        int timer = 0;
        set<int> artPoints;
        
        for (int i = 0;i < V;i++){
            if(!vis[i]) {
                dfs(i,-1,adj,tin,low,vis,timer, artPoints);
            }
        }
        vector<int> result(artPoints.begin(), artPoints.end());
        
        if(result.empty()) {
            return {-1};
        
        }
        return result;
    }
    
    void dfs(int node, int parent, vector<int> adj[], vector<int>& tin, vector<int>& low,
             vector<bool>& vis, int& timer, set<int>& artPoints) {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int children = 0;
        
        for (int neighbor : adj[node]) {
            if ( neighbor == parent) {
                continue;
            }
            if (vis[neighbor]) {
                low[node] = min(low[node], tin[neighbor]);
            } else {
                children++;
                dfs(neighbor, node,adj,tin,low,vis, timer,artPoints);
                low[node] = min(low[node], low[neighbor]);
                
                if(parent != -1 && low[neighbor] >= tin[node]) {
                    artPoints.insert(node);
                }
            }
        }
        if (parent == -1 && children > 1) {
            artPoints.insert(node);
        }
    }
};