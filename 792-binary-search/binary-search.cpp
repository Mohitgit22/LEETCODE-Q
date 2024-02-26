typedef long long  ll; // typedef int to long long

class Solution {
public:
     int bs(vector<int>& nums, int target, int low, int high) {
         if(low > high)
         return -1;
         
         ll mid = (low + high)/2;
         if(nums[mid] == target)
         return mid;
         else if(nums[mid] < target)
         return bs(nums, target, mid+1, high);
         else
         return bs(nums, target, low, mid-1);

     }
    int search(vector<int>& nums, int target) {
        //iterative soln :

        // ll low = 0;
        // ll high = nums.size()-1;
        // while(low <= high) {
        //     int mid = low+(high-low)/2;
        //     if(nums[mid] == target)
        //     return mid;
        //     else if(nums[mid] < target)
        //     low = mid+1;
        //     else
        //     high = mid-1;
        // }
        // return -1;

        //recursive soln :

        ll low = 0;
        ll high = nums.size()-1;
        return bs(nums,target,low, high);
    }
};