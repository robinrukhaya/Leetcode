class Solution {
  public:
        void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
            visited[node] = true;
            for(auto neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    dfs(neighbor, adj, visited, st);
                }
            }
            st.push(node);
        }
        void dfs2(int node, vector<vector<int>>& adj, 
              vector<bool>& visited) {
            visited[node] = true;
            for(auto neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    dfs2(neighbor, adj, visited);
                }
            }
        }
        int kosaraju(int V,vector<vector<int>>& edges) {
            vector<vector<int>> adj(V);
            for(auto edge : edges) {
                adj[edge[0]].push_back(edge[1]);
            }
            vector<bool> visited(V,false);
            stack<int> st;
            for(int i = 0 ; i < V;i++) {
                if(!visited[i]) {
                    dfs(i,adj,visited,st);
                }
            }
        vector<vector<int>> transAdj(V);
        for(int i = 0;i <V;i++) {
            for(auto neighbor : adj[i]) {
                transAdj[neighbor].push_back(i);
            }
        }
        
        fill(visited.begin(), visited.end(), false);
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(!visited[node]) {
                dfs(node, transAdj, visited, st);
                scc++;
            }
        }
        return scc;
        
        
    }
};