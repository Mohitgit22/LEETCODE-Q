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






// n C++, operator() is a special function called the "function call operator" or "parentheses operator." It allows objects of a class to be used as if they were functions themselves. When you define operator() inside a class, you're essentially defining how objects of that class behave when they are "called" like functions.

// In the context of your code snippet, the operator() function is defined inside the compare class. This class is used as a custom comparator for a priority queue, where elements are pairs of integers (pair<int, int>).

// Here's what the operator() function is doing in your code:

// It takes two parameters a and b, which are pairs of integers (pair<int, int>).
// It compares these pairs based on their first and second elements.
// If the first element of a is greater than the first element of b, it returns true.
// If the first element of a is less than the first element of b, it returns false.
// If the first elements are equal, it compares the second elements:
// If the second element of a is greater than the second element of b, it returns false.
// Otherwise, it returns true.
// In essence, this operator() function defines the sorting logic for the pairs of integers in your priority queue. It determines how the pairs should be ordered relative to each other when the priority queue needs to compare them.