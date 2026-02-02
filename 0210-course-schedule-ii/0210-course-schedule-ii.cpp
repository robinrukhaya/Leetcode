class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj, vector<int>& vis, 
            vector<int>& pathVis,vector<int>& order){
        vis[node] = 1;
        pathVis[node]= 1;

        for (int neigh : adj[node]) {
            if (vis[neigh] == 0) {
                if (dfs(neigh,adj,vis,pathVis,order))
                   return true;
            }
            else if (pathVis[neigh]== 1) {
                return true;
            }
        }
        pathVis[node]= 0;
        order.push_back(node);
        return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<int> order;
        for(int i = 0;i<numCourses;i++) {
            if (vis[i]== 0) {
                if (dfs(i,adj,vis,pathVis,order))
                    return {};
            }
        }
        reverse(order.begin(),order.end());
        return order;
    }
};