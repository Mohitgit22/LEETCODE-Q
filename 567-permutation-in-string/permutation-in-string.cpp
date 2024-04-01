class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         unordered_map<char,int>m;
        int n=s2.length();
        int k=s1.length();
        for(auto i:s1)
            m[i]++;
        int count=m.size();
        int i=0,j=0;
        while(j<n)
        {
            if(m.count(s2[j]))// If you want to check if a key exists and get the count of occurrences of that key (which will always be 0 or 1), you can use count in std::map.
            {
                m[s2[j]]--;
               if(m[s2[j]]==0)
                   count--;
            }
            
            if((j-i+1) <k)
                j++;
            
            else if((j-i+1) ==k)
            {
                if(count==0)
                    return true;
                
                if(m.count(s2[i]))
                {
                  m[s2[i]]++;
                    
                  if (m[s2[i]]==1)
                  count++;
                        
                }
                          i++;
                          j++;
            }
           
        }
           return false;
        
    }
};