class compare {
  public: 
       bool operator() (pair<int, int>& a, pair<int, int>&b) {
        if(a.first > b.first)
          return true;
        else if(a.first < b.first)
          return false;
        else {
            if(a.second > b.second)
            return false;
            else
            return true;
        }
       }
};



class Solution {
public:
    //heap question

    typedef pair<int, int> P;
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<P, vector<P>, compare> pq;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }

        vector<int> ans;
        while(!pq.empty()){
            int freq = pq.top().first;
            int val = pq.top().second;

           pq.pop();
            while(freq!=0){
                ans.push_back(val);
                freq--;
            }
        }
        return ans;
    }
};