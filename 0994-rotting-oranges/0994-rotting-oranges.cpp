class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int  n  = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j <m;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                   fresh++;
            }
        }

        int time = 0;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        while(!q.empty() && fresh >0) {
            int size = q.size();

            while(size--) {
                auto[r,c] = q.front();
                q.pop();

                for(int k = 0;k<4;k++){
                    int nr= r+dr[k];
                    int nc = c+dc[k];

                    if(nr >= 0 && nr <n  && nc >= 0 && nc <m &&
                     grid[nr][nc]==1) {
                      grid[nr][nc]= 2;
                      fresh--;
                      q.push({nr,nc});
                    }
                }
            }
            time++;
        }
        return fresh ==0 ? time: -1;
    }
};