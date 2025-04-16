class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long result = 0;
        int pairs = 0;
        int i = 0, j = 0;

        int n = nums.size();

        while( j < n){
          pairs += mp[nums[j]];
          mp[nums[j]]++;

          while(pairs >= k){
            result += (n-j);
            mp[nums[i]]--;
            pairs -= mp[nums[i]];
            i++;
          }
          
          j++;
        }
        return result;
    }
};