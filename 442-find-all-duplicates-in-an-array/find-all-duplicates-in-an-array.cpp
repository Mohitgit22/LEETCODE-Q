class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> map;
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto it:map){
            if(it.second>=2)
            v.push_back(it.first);
        }
        return v;
    }
};