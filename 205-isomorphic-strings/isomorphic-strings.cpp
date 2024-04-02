class Solution {
public:
    bool isIsomorphic(string s, string t) {
         unordered_map<char, int > mp1, mp2;
         
        //  if(s.length() != t.length())
        //      return false;
       
         for(auto& i:s){
            if(mp1.count(i)!=0)
               continue;
            mp1[i] = mp1.size();
         }

         for(auto& j:t){
            if(mp2.count(j)!=0)
              continue;
            mp2[j] = mp2.size();
         }
          for (int k = 0; k < s.size(); k++) {
            if (mp1[s[k]] != mp2[t[k]]) 
            return false;
        }
      return true;
    }
};