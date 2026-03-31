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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToNode;
        int nodeCount = 0;

        for (auto account : accounts) {
            for(int i = 1; i <account.size();i++) {
                if(emailToNode.find(account[i]) == emailToNode.end()) {
                    emailToNode[account[i]] = nodeCount++;
                }
            }
        }
        DSU dsu(nodeCount);

        for(auto account : accounts) {
            int firstNode = emailToNode[account[1]];
            for(int i = 2;i <account.size();i++) {
                dsu.unionByRank(firstNode, emailToNode[account[i]]);
            }
        }
        map<int , vector<string>> rootToEmails;
        for(auto [email, node] : emailToNode) {
            int root = dsu.find(node);
            rootToEmails[root].push_back(email);
        }
        
        map<int, string> nodeToName;
        for(auto account : accounts) {
            int node = emailToNode[account[1]];
            int root = dsu.find(node);
            nodeToName[root] = account[0];
        }

        vector<vector<string>> result;

        for(auto [root, emails] : rootToEmails) {
            vector<string> merged;
            merged.push_back(nodeToName[root]);
            sort(emails.begin(),emails.end());
            for(auto email: emails) merged.push_back(email);
            result.push_back(merged);
        }
        return result;

    }
};