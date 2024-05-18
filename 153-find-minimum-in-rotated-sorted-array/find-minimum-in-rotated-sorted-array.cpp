class Solution {
public:
    int findMin(vector<int>& nums) {
    //     int low = 0;
    //     int high = nums.size()-1;
    //     int ans = INT_MAX;
    //     while(low <= high) {
    //         int mid = low +( high - low ) /2;
    //         if( nums[low] <= nums[mid]){
    //             ans = min(ans, nums[low]);
    //             low = mid + 1;
    //         }else{
    //             ans = min(ans, nums[mid]);
    //             high = mid -1;
    //         }
    //     }
    //     return ans;
    // }

    int start = 0;
    int end = nums.size() -1;
    int n = nums.size();
    while(start <= end) {
        if(nums[start] < nums[end])
          return nums[start];
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
          return nums[mid];
        else if(nums[mid] >= nums[start])
          start = mid +1;
        else 
          end= mid - 1;
    }
    return -1;
    }
};