class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum = 0;
        int maxsum = 0;
        bool flag = false;

        for(int i = 0; i < nums.size(); i++) {
            cursum += nums[i];

            if(cursum >= maxsum){
            maxsum = cursum;
            flag = true;
            }

            if(cursum < 0)
            cursum = 0;
        }

        if(flag)
        return maxsum;
        else
        return *max_element(nums.begin(), nums.end());
    }
};