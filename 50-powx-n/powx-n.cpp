class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;

        //for negative powers, at last
        int m = n;
        n = abs(n);

        while(n > 0) {
           if(n%2 == 1){
            ans = ans * x;
            n = n-1;
           }else{
            n = n>>1;
            x = x*x;
           }
        }
        
        // cout << ans<< " ";
        if(m < 0) 
        ans = 1.0/ans;
     
        return ans;
    }
};