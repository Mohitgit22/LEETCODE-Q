class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
       int cnt = 0;
       int majel = 0;
       for(int i = 0; i < nums.size(); i++) {
        if(cnt == 0) {
            majel = nums[i];
            cnt = 1;
            continue;
        }

        if(majel == nums[i])
           cnt++;
        else if(majel != nums[i]){
           cnt--;
        }
    }
      
      cnt = 0;
       for(auto it : nums){
        if(it == majel)
        cnt++;
       }

       if(cnt > (nums.size()/2));
       return majel;

       return -1;
    }
};