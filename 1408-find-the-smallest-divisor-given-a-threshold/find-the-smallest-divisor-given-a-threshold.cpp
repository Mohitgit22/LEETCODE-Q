class Solution {
public:
      //dytto same --koko eating bananas 875
     long long divisonsum(vector<int>& nums, int k)
    {
        long long ans=0;
        for (int i=0; i<nums.size(); i++){
            ans+= ceil((double)nums[i]/(double)k);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
         int low=1;
        int high= *max_element(nums.begin(),nums.end());
        while (low <= high)
        {
            int mid= low+ (high-low)/2;
            if (divisonsum(nums,mid)<=threshold)
            {
                high= mid-1;
            }
            else low= mid+1;
        }
        return low;
    }
};