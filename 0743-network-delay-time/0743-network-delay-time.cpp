class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for (auto &it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n+1,1e9);
        dist[k] = 0;

        pq.push({0,k});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int time = top.first;
            int node = top.second;

            for (auto &neighbor: adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (time+weight < dist[adjNode]) {
                    dist[adjNode] = time+weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxi = 0;

        for (int i = 1; i <= n;i++) {
            if (dist[i] == 1e9)
                return -1;
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};