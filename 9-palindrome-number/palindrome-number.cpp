class Solution {
public:
    bool isPalindrome(int x) {
         long  int before=x;
         long int num=0;
     while(x>0){
        long int p=x%10;
         num=num*10+p;
         x=x/10;
     }
     if(num==before)
     return true;

     return false;
    }
};