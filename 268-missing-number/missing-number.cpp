class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long arr_sum = 0;
        int n = nums.size();
        long long sum = (n*(n+1))/2;

        for(auto it : nums) {
            arr_sum += it;
        }
        return sum - arr_sum;

    }
};