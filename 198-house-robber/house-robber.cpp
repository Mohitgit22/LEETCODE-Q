class Solution {
public:
    int bottomup(int n, vector<int>& nums, vector<int>& dp) {
         dp[0] = nums[0];

         for(int i = 1; i < n; i++) {
            int pick = nums[i];
            if(i>1)
             pick  = pick + dp[i-2];

             int notpick = dp[i-1];

             dp[i] = max(pick, notpick);
         }

         return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 0);
        return bottomup(n, nums, dp);
    }
};