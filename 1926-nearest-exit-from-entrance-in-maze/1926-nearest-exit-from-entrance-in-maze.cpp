class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(m,vector<int>(n, 0));

        int sr = entrance[0];
        int sc = entrance[1];

        q.push({{sr,sc},0});
        visited[sr][sc] = 1;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++) {

                int newr = r+delrow[i];
                int newc = c+ delcol[i];

                if(newr >= 0 && newr < m &&
                    newc >= 0 && newc < n &&
                    maze[newr][newc] == '.' &&
                    !visited[newr][newc]) {

                    if(newr == 0 || newr == m-1 || newc == 0 || newc == n-1) {
                        return dist+1;
                    }
                    visited[newr][newc] = 1;
                    q.push({{newr,newc}, dist+1});
                }
            }
        }
        return -1;
    }
};