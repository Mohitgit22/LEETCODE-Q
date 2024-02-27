class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        //Using Binary Search
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1;
        int high = nums.size()-2;
        while(low <= high) {
            int mid = (low + high)/2;
            //if left and right side of the element is not same , then it is single element
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            return nums[mid];
            
            //eliminating left half
            if(mid % 2 ==1 && nums[mid] == nums[mid-1] || mid %2 ==0 && nums[mid] == nums[mid + 1])
               low = mid + 1;
            else //eliminate the right half
               high = mid - 1;
        }
        return -1;
    }
};


  // Using BIT Manipulation
        // int xorel = 0;
        // for(int i =0; i<nums.size(); i++) {
        //     xorel = xorel ^ nums[i];
        // }
        // return xorel;
