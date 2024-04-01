class Solution {
public:
    string minWindow(string s, string t) {
         int i =0;
         int j =0;
         unordered_map<char, int> mp;
          int minlen = INT_MAX;
          int start = 0;
         for(auto it: t)
             mp[it]++;
        
         int count = mp.size();

        if(t.length() > s.length() || s.empty())
        return "";


         while( j < s.length() ) {
               if(mp.find(s[j]) == mp.end())
                          j++;
               else if (mp.find(s[j]) != mp.end()) {
                        mp[s[j]]--;
                        if (mp[s[j]] == 0)
                         count--;
                    
                  //we will not erase s[j] from map b'coz it can go in negative.  

                  //ye code ko bahar 2nd loop mein nhi likhna hai as ye baar baar calculate
                  //hoga last tak s string ke 
          if(count==0){
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) {
                            count++;
                            if(j-i+1<minlen){
                                minlen=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                }  
            }
            j++;
               }
         }

        //  cout<<"size is" << j-start+1;
        if(minlen == INT_MAX) 
        return "";
        else
        return s.substr(start,minlen);
    }
};