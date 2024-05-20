class Solution {
public:
    // eg [2.1.1.2]
    //o/p : 4

    // recursive approach -- not applicable
    // int solve(vector<int>& nums, int i) {
    //     if(i >= nums.size()) 
    //         return 0;

    //     int steal = nums[i] + solve(nums, i+2);
    //     int skip = solve(nums, i+1);

    //     return max(steal, skip);
    //     }
    
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     return solve(nums, 0);
    // }

   // using memoization
//    int t[101];
//    int solve(vector<int>& nums, int i, int n) {
//         if(i >= n)
//         return 0;

//         if(t[i]!=-1)
//         return t[i];

//        int steal = nums[i] + solve(nums, i+2, n);
//        int skip = solve(nums, i+1, n);
//         return t[i] = max(steal, skip);
//    }

//      int rob(vector<int>& nums) {
//         int n = nums.size();
//         memset(t, -1, sizeof(t));
//         return solve(nums, 0,n);
//     }  





   //using bottom up approach

    int rob(vector<int>& nums) {
         int n = nums.size();
         int t[n+1];

         t[0] = 0;
         t[1] = nums[0];

         for(int i = 2; i<=n; i++) {
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(skip, steal);
         }
         return t[n];
    }  
};