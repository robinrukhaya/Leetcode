class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0) return {};

        int  m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j]== 0) {
                    q.push({i,j});
                    vis[i][j]= 1;
                    dist[i][j]= 0;
                }
            }
        }

        int dr[4] = {-1,1,0,0};
        int dc[4] =  {0,0,-1,1};

        while(!q.empty()) {
            auto[r,c] = q.front();
            q.pop();

            for(int k = 0; k<4;k++){
                int nr = r +dr[k];
                int nc = c +dc[k];

                if(nr >= 0 && nr <n && nc >= 0 && nc <m && !vis[nr][nc]) {
                    vis[nr][nc]= 1;
                    dist[nr][nc] = dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return dist;
    }
}; 