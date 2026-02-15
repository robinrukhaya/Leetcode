class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> adj;
    unordered_map<string, int> level;

    void dfs(string word,string beginWord,vector<string>& path) {
        
        if (word == beginWord) {
            reverse(path.begin(),path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto parent : adj[word]) {
            path.push_back(parent);
            dfs(parent, beginWord,path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        if (st.find(endWord) == st.end())
            return {};
        
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while(!q.empty()) {
            string word = q.front();
            q.pop();

            int currLevel = level[word];

            for (int i = 0; i <word.size();i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;


                    if(st.find(temp) != st.end()) {

                        if (!level.count(temp)) {
                            level[temp] = currLevel+1;
                            q.push(temp);
                        }

                        if(level[temp] == currLevel+1)
                            adj[temp].push_back(word);
                    }
                }
            }
        }
        if(!level.count(endWord))
            return {};
            
        vector<string> path = {endWord};
        dfs(endWord,beginWord,path);

        return ans;
    }
      
};