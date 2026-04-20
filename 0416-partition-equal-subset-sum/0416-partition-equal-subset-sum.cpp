class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;

        int target  = sum /2;

        vector<bool> dp(target+1,false);

        dp[0] = true;

        for (int num : nums) {
            for(int t = target; t >= num;t--) {
                dp[t] = dp[t] || dp[t-num];
            }
        }
        return dp[target];
    }
};