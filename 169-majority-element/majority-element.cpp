class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp) {
            int x = it.second;
            if(x > floor(n/2)){
                return it.first;
            }
        }
        return -1;
    }
};