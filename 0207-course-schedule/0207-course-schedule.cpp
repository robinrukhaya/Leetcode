class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&        visited,vector<int>& recStack) {
        visited[node]=1;
        recStack[node] = 1;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(dfs(neighbor,adj,visited,recStack))
                   return true;
            }
        
            else if(recStack[neighbor]) {
                return true;
            }
        }

    recStack[node] = 0; 
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto p: prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }

        vector<int> visited(numCourses,0);
        vector<int> recStack(numCourses,0);

        for(int i = 0;i<numCourses;i++){
            if(!visited[i]) {
                if(dfs(i,adj,visited,recStack))
                    return false;
            }
        }
        return true;
    }
};