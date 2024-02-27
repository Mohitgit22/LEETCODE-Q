class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorel = 0;
        for(int i =0; i<nums.size(); i++) {
            xorel = xorel ^ nums[i];
        }
        return xorel;
    }
};