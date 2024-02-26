typedef long long  ll; // typedef int to long long

class Solution {
public:
    int search(vector<int>& nums, int target) {
        ll low = 0;
        ll high = nums.size()-1;
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(nums[mid] == target)
            return mid;
            else if(nums[mid] < target)
            low = mid+1;
            else
            high = mid-1;
        }
        return -1;
    }
};