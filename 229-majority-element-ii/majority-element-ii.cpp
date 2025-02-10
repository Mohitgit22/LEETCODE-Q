class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int maj1 = NULL, maj2 = NULL, count1 = 0, count2 = 0;
        int n = nums.size();

     for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == maj1)
        count1++;
        else if(nums[i] == maj2)
        count2++;
        else if(count1 == 0){
            maj1 = nums[i];
            count1 = 1;
        }else if(count2 == 0){
            maj2 = nums[i];
            count2 = 1;
        }else{
            count1--;
            count2--;
        }
     }

     count1 = 0;
     count2 = 0;
     vector<int> ans;
     for(auto it : nums){
        if(it == maj1)
        count1++;
        else if(it == maj2)
        count2++;
     }
     if(count1 > floor(n/3))
     ans.push_back(maj1);
     if(count2 > floor(n/3))
     ans.push_back(maj2);

     return ans;
    }
};