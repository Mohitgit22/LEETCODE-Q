class Solution {
public:
    #include<deque>
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // The problem statement is a little vague.
        // We need to return the Maximum Element from each window.
        // max sliding window = list of max element for each window
       
       deque<int> dq;
       vector<int> ans;
       for(int i = 0; i< nums.size(); i++) {
        //if the front element of deques is index (i-k)
        //then it is out of the window (from back side)
        // so we will have to pop the front most element
        if(!dq.empty() && dq.front()==i-k)
              dq.pop_front();
            // we are storing indices in dq.
            // while nums[last_indice_stored] < nums[i], 
            //we will have to pop the last element
        while(!dq.empty() && nums[dq.back()] <= nums[i])
               dq.pop_back();

        //everything's fine -> push the index i
        dq.push_back(i);
        if(i+1 >= k)
               ans.push_back(nums[dq.front()]);//as soon window size becomes k ,push the max element by using the index 
               //which will always be present at front of the deque;
       }

       return ans;













        //  int i = 0, j =0 ;
        //  int size = nums.size();
        //  deque<int> window;
        //  vector<int> ans;
        //  int mx = INT_MIN;
        //  while(j < size) {
        //     // mx = max(mx, nums[j]);
        //     // sum = sum + nums[j];
        //     window.push_back(nums[j]);
        //     if(j-i+1 < k){    
        //        j++;
        //     }
        //     else if(j-i+1 >= k){
        //          ans.push_back((*max_element(window.begin(), window.end())%(int)(1e9+7)));
        //          i++;
        //          j++;
        //           window.pop_front();
        //     }     
        //  }
        // //  delete window;
        // // for(int i =0; i< ans.size(); i++){
        // //     cout<<ans[i]<<" ";
        // // }
        //  return ans;


    }
};