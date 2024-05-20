class Solution {
public:
    int t[101];

    //top down approach -- memoization
    // int solve(vector<int>& nums, int i, int n) {
    //     if( i>= n)
    //     return 0;

    //     if(t[i] != -1)
    //     return t[i];

    //     int steal = nums[i] + solve(nums, i + 2, n);
    //     int skip = solve(nums, i + 1, n);

    //     return t[i] = max(steal, skip);
    // }


    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     if(n == 1)
    //     return nums[0];

    //     if(n == 2)
    //     return max(nums[0], nums[1]);

    //     memset(t, -1, sizeof(t));

    //     //take 0th house
    //     int take_0th_house = solve(nums, 0, n-1);
    //     //not take 0th house
    //     memset(t, -1, sizeof(t));
    //     int nottake_0th_house = solve(nums, 1, n);

    //     return max(take_0th_house,nottake_0th_house );
    // }



    // bottom up approach
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return nums[0];
       vector<int> t(n+1, 0);
       //t[i] = money stolen when u have i houses
       t[0] = 0;
       //case1  = take 1st house - hence skip the last house 
       for(int i = 1; i <= n-1; i++) {
        int skip = t[i-1];
        int steal = nums[i-1] + ((i-2 >= 0 )? t[i-2] : 0);
        t[i] = max(skip, steal);
       }
       int res1 = t[n-1];
       t.clear();
   
       //case2  = skip 1st house - hence u can take the last house
       t[0] = 0;
       t[1] = 0;
       for(int i = 2; i <= n; i++) {
        int skip  = t[i-1];
        int steal  = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0);
        t[i] = max(skip, steal);
       }
       int res2 = t[n];

       return max(res1, res2);
    }
};