class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int i = 0, cnt = 0;
        int firstel, secondel, thirdel;
        while(i<n and mp.size()!=(n-i)){
            firstel = nums[i];
            cout<<"firstel is :"<<firstel << " "<<endl;
            if(i+1 < n){
               secondel = nums[i+1];
               cout<<"secondel is : "<<secondel << " "<<endl;
               mp[secondel]--;
               if(mp[secondel] == 0) mp.erase(secondel);
            } 
            if(i+2 < n) {
                thirdel = nums[i+2];
                cout<<"thirdel is : "<<thirdel<< " "<<endl;
                mp[thirdel]--;
                if(mp[thirdel] == 0) mp.erase(thirdel);
            }
        mp[firstel]--;
        if(mp[firstel] == 0) mp.erase(firstel);

        cout<<"map size is"<<mp.size()<<endl;
        cout<<"i is now at : "<<i<<endl;
        cnt++;
          cout<<"new i is: "<< i +3<<endl;
             i = i + 3;
        }
        return cnt;
    }
};