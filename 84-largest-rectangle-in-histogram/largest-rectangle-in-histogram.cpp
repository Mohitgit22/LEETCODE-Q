class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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

    //     cout<<"left"<<endl;
    //    for(auto it: left){
    //     cout<<it<<" ";
    //    }
    //    cout<<endl;
    //    cout<<"right"<<endl;

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
       
    //    for(auto it: right){
    //     cout<<it<<" ";
    //    }
        


        //finding the width
        vector<int> width(n,1);
        for(int i = 0; i < n ; i++) {
            width[i] = right[i] - left[i] - 1;
        }

    //     cout<<"width"<<endl;
    //     for(auto it: width){
    //     cout<<it<<" ";
    //    }
      
        //finding the area
        vector<int> area(n,0);
        for(int i = 0; i < n ; i++) {
            area[i] = width[i]* heights[i];
        }
    //    cout<<"area"<<endl;
    //     for(auto it: area){
    //     cout<<it<<" ";
    //    }


       int ans = *max_element(area.begin(), area.end());
       return ans;

    }
};