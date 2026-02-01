class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixMin(n);
        suffixMin[n-1]= nums[n-1];

        for(int i = n-2;i>= 0;i--) {
            suffixMin[i] = min(nums[i],suffixMin[i+1]);
        }
        int best = INT_MAX;

        for(int i = 1;i<=n-2;i++) {
            best = min(best,nums[i]+suffixMin[i+1]);
        }
        return nums[0]+best;
    }
};