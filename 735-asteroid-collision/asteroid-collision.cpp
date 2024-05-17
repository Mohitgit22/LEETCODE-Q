// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int> st;
//         vector<int> ans;
//         int n = asteroids.size();
//         if(n==0)
//           return ans;

//         for(int i = n-1; i>=0; i--) {
//             if(st.empty())
//               st.push(asteroids[i]);
//             else if(!st.empty() &&( (st.top()>=0 && asteroids[i] >=0) || (st.top()<0 && asteroids[i]<0)))
//               st.push(asteroids[i]);
//             else if(!st.empty() && abs(st.top()) == abs(asteroids[i])){
//                 if(st.top() < 0 && asteroids[i] > 0)
//                 st.pop();
//                 else
//                 continue;
//             }
//             else if(!st.empty() && abs(st.top()) < abs(asteroids[i])){
//                 if(st.top() < 0 && asteroids[i] > 0){
//                 st.pop();
//                 st.push(asteroids[i]);
//                 }else
//                 continue;
//             }else if(!st.empty() && abs(st.top()) >  abs(asteroids[i])){
//                  if(st.top() < 0 && asteroids[i] > 0)
//                  continue;
//                  else
//                  st.push(asteroids[i]);
//             }
//     }

//     while(!st.empty()){
//         ans.push_back(st.top());
//         st.pop();
//     }

//     // reverse(ans.begin(),ans.end());
//     return ans;
//     }
// };


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        int n = asteroids.size();

        for(int i=0; i<n; i++){
            int x = asteroids[i];
            bool flag = 1;
            while(!st.empty() && st.top() > 0 && x < 0){
                int first = st.top();
                int second = abs(x);
                st.pop();

                if(first > second){
                    x = first;
                }   

                else if(first == second){
                    flag = 0;
                    break;
                }
            }
            if(flag) st.push(x);
        }
        
        n = st.size();
        vector<int> ans(n);
        n--;
        while(!st.empty()){
            ans[n] = st.top();
            st.pop();
            n--;
        }
        return ans;
    }
};