class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0 ;
        int cursum = 0;

        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
          cursum += nums[i];
          
          if(cursum - k == 0){
            cnt++;
          } 
          if(mp.find(cursum - k) != mp.end()){
            cnt += mp[cursum-k];
          }

          mp[cursum]++;
        }

        return cnt;
    }
};