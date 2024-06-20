class Solution {
public:
    int thirdMax(vector<int>& nums) { 
     unordered_set<int> st(nums.begin(),nums.end());
     
      if(st.size() < 3)
      return *max_element(st.begin(), st.end());

       vector<int> vec;
     for(auto it : st) {
       vec.push_back(it);
     }

    sort(vec.begin(), vec.end());
    int n = vec.size();

    return vec[n-1-2]; //last 3rd element
    }
};