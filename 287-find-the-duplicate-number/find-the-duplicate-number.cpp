class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();

        for(int i =0; i<n; i++) {
            mp[nums[i]]++;
        }

        for( auto it: mp) {
            if(it.second != 1)
            return it.first;
        }
        return -1;

        // int xor1=0;
        // int xor2 = 0;
        // for(int i =1; i<=n; i++) {
        //     xor1 = xor1^nums[i-1];
        //     xor2 = xor2^i;
        // }

        // int ans = xor1 ^ xor2;
        // return ans;
    }
};