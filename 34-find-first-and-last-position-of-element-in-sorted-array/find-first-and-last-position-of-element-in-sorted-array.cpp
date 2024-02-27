class Solution {
public:
     int firstOccur(vector<int>& nums, int n, int x) {
         int low =0;
         int high =n-1;
         int ans = -1;
         while(low <= high) {
             int mid = low + (high - low) / 2;
             if(nums[mid] == x) {
                 ans = mid;
                 high = mid -1;
             }else if(nums[mid] < x)
             low= mid+1;
             else
             high = mid -1;
         }
         return ans;
     }

       int lastOccur(vector<int>& nums, int n, int x) {
         int low =0;
         int high =n-1;
         int ans = -1;
         while(low <= high) {
             int mid = low + (high - low) / 2;
             if(nums[mid] == x) {
                ans = mid;
                low= mid+1;
              
             }else if(nums[mid] > x)
                high = mid -1;
                else
                low= mid + 1;
         }
         return ans;
     }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(firstOccur(nums,nums.size(), target));
        v.push_back(lastOccur(nums,nums.size(),target));
        return v;
    }
};