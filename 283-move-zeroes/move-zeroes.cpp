class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1)
        return ;

        int i = 0;
        int n = nums.size();
        for(int j = 0; j<nums.size(); j++) {
            if(nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
        }

        for(int j = i; j< n ;j++){
            nums[j] = 0;
        }
    }
};