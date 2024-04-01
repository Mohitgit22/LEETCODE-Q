class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           unordered_map<char, int> mp;
           int i = 0;
           int j = 0;
           int size = s.length();
           int maxi = 0;
           while(j < size) {
            mp[s[j]]++;
            if(mp.size() == (j-i+1)){
                maxi = max(maxi ,(j-i+1));
               j++;
            }
            else if(mp.size() < (j-i+1)){
                while(mp.size() < (j-i+1)) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                       mp.erase(s[i]);
                    i++;
                }
                j++;
            }     
           }
           return maxi;
    }
};