class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int> v;
         stack<int> st;

         for(int i = nums2.size()-1; i>=0; i--) {
            if(st.empty())
              v.push_back(-1);
            else if(!st.empty() && st.top() > nums2[i])
              v.push_back(st.top());
            else if(!st.empty() && st.top() <= nums2[i]){
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }

                if(st.empty())
                  v.push_back(-1);
                else 
                  v.push_back(st.top());
            }
            st.push(nums2[i]);
         }
         reverse(v.begin(), v.end());
         v.push_back(-1);

         map<int, int> mp;
         for(int i =0; i< nums2.size(); i++) {
            mp[nums2[i]] = i;
         }

         vector<int> ans;
         for(int i = 0; i< nums1.size(); i++) {
             int index = mp[nums1[i]];
             ans.push_back(v[index]);
         }
         return ans;
    }
};