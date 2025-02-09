class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size(); i++){
           int cur = nums[i];

           int moreneeded = target - cur;
           if(mp.find(moreneeded) != mp.end()){
            return {mp[moreneeded], i};
           }
           mp[cur] = i;
        }
        return {-1, -1};
    }
};