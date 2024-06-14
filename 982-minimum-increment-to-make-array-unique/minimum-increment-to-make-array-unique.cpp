class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
       
       // 1. giving tle mine sol

        // vector<bool> vis(1e5, false);
        // int cnt= 0 ;

        // for(int i = 0; i < nums.size(); i++) {
        //     if(!vis[nums[i]]){
        //     vis[nums[i]]  = true;
        //     }
        //     else{
        //         bool flag = false;
        //         while(flag == false) {
        //             nums[i] = nums[i] + 1;
        //              cnt++;
        //             if(vis[nums[i]] ==  false){
        //              flag = true;
        //              vis[nums[i]] = true;
        //             }
        //         }   
        //     }
        // }
        // return cnt;

       //2. soln 2
       sort(nums.begin(), nums.end());
       int cnt = 0;

       for(int i = 1; i < nums.size(); i++) {
        if(nums[i] <= nums[i-1]) {
            cnt += nums[i-1] - nums[i] + 1;
            nums[i] = nums[i-1] + 1;
        }
       }
       return cnt;
    }
};
