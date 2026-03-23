class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();

        for(int x :nums){
            freq[x]++;

            if(freq[x] >n/2) {
                return x;
            }
        }
        return -1;
    }
};