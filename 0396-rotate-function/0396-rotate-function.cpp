class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0, F = 0;
        
        // Step 1: compute sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }
        
        long maxi = F;
        
        // Step 2: compute F(k) using relation
        for (int k = 1; k < n; k++) {
            F = F + sum - (long)n * nums[n - k];
            maxi = max(maxi, F);
        }
        
        return maxi;
    }
};