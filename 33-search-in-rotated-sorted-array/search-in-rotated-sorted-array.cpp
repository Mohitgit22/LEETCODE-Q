class Solution {
public:

    int minindex(vector<int>& nums){
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int index = -1;
        while( s<= e) {
            if(nums[s] < nums[e])
            return s;
            
            int mid = s + (e - s) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n -1) % n;
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev]){
                return mid;
            }
            else if(nums[s] <= nums[mid])
                s = mid + 1;
            else 
              e = mid -1;
            }
            return index;
        }

    int BS(vector<int>& nums,int start, int end, int target){
        int s = start;
        int e = end;
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
             return mid;
            else if(nums[mid] < target)
              s = mid + 1;
            else 
              e = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

       int n = nums.size() ;
       int index = minindex(nums);
    //    cout<<"index is "<<index<<endl;
       int left = BS(nums, 0, index - 1, target);
       int right = BS(nums, index, n-1, target);

    //    cout<<left <<" hi"<<right<<endl;
       if(left == -1 && right == -1)
        return -1;
       else if(left != -1)
        return left;
        else
        return right;
    }
};