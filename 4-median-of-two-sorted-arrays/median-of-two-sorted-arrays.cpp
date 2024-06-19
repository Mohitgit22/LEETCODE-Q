class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
            
        }
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        int p=v.size();

        if(p%2!=0){
            int c=p/2;
            int q=v[c];
           return double(q);
        }
        else{
            int t=p/2;
            int r=t-1;
            double e=double((v[t]+v[r]))/2;
            return double(e);
        }
    }
};