class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int numssum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the total sum and the target sum are both odd or both even, then only we can have a possible subset
        if ((numssum + target) % 2 != 0 || numssum < target ||  ((numssum + target)/2) < 0)
            return 0;

        int sum = (target + numssum) / 2;
        //count the no. if subsets having sum equal to above sum
        //simple question
        int m = nums.size();
        int n = sum;
        int dp[m + 1][n + 1];

        for (int i = 0; i < n + 1; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]; // exclude + include
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};
