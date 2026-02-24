class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> dist(m,vector<int>(n,1e9));

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r== m-1 && c == n-1)
                return effort;
            
            for(int i =0 ; i <4;i++) {
                int newr= r+ delrow[i];
                int newc = c + delcol[i];

                if(newr >= 0 && newr < m && newc >= 0 && newc <n) {
                    int weight = abs(heights[r][c] - heights[newr][newc]);
                    int newEffort = max(effort,weight);

                    if(newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, { newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};