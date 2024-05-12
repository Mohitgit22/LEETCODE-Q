class Solution {
public:
      //aditya verma  -> stack playlist
     int MAH(vector<int> heights) {
         vector<int> left,right;
        int pseudoind1 = -1;
        int pseudoind2 = heights.size();
        int n = heights.size();

        //finding NSL;
        stack<pair<int, int>> st;
        for(int i = 0; i < n; i++) {
            if(st.empty())
              left.push_back(pseudoind1);
            else if(!st.empty() && st.top().first< heights[i])
                left.push_back(st.top().second);
            else if(!st.empty() && st.top().first>= heights[i]){
                while(!st.empty() && st.top().first >= heights[i])
                 st.pop();
                if(st.empty())
                 left.push_back(pseudoind1);
                else
                  left.push_back(st.top().second);
            }
            
            st.push({heights[i], i});
        }

        while(!st.empty()){
            st.pop();
        }

        //finding NSR
        for(int i = n-1; i >=0 ; i--) {
            if(st.empty())
              right.push_back(pseudoind2);
            else if(!st.empty() && st.top().first< heights[i])
                right.push_back(st.top().second);
            else if(!st.empty() && st.top().first>= heights[i]){
                while(!st.empty() && st.top().first >= heights[i]){
                 st.pop();
                }
                if(st.empty())
                 right.push_back(pseudoind2);
                else
                  right.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
       
        //finding the width
        vector<int> width(n,1);
        for(int i = 0; i < n ; i++) {
            width[i] = right[i] - left[i] - 1;
        }

      
        //finding the area
        vector<int> area(n,0);
        for(int i = 0; i < n ; i++) {
            area[i] = width[i]* heights[i];
        }

       int ans = *max_element(area.begin(), area.end());
       return ans;
     }


    int maximalRectangle(vector<vector<char>>& matrix) {
         int n = matrix.size();
         int m = matrix[0].size();
      
         vector<int> v;
         for(int i = 0; i < m ;i++) {
          v.push_back(matrix[0][i] == '0' ? 0 : 1);
         }
        
        int ans = MAH(v);
         for(int i = 1; i < n ; i++) {
            for(int j = 0; j< m; j++) {
                if(matrix[i][j] == '0')
                  v[j] = 0;
                 else
                  v[j] = v[j] + 1;
            }
            ans = max(ans, MAH(v));
         }
         return ans;
    }
};