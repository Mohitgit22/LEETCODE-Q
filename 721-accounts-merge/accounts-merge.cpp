class Solution {
public:
   vector<int> parent;
   vector<int> rank;
   vector<int> size;

    int find(int x)
      {
      //add code here
      if(x == parent[x])
      return x;
       
      return parent[x] = find(parent[x]);
       }

void unionByRank(int x, int y) 
{
	int x_parent = find(x);
	int y_parent = find(y);
	
	if(x_parent == y_parent)
	  return;
	  
	if(rank[x_parent] > rank[y_parent])
      parent[y_parent] = x_parent;
    else if(rank[x_parent] < rank[y_parent])
      parent[x_parent] = y_parent;
    else {
        parent[y_parent] = x_parent;
        rank[x_parent]++;
    }
}

     void unionBySize(int u, int v) {
        int u_parent = find(u);
        int v_parent = find(v);

        if (u_parent == v_parent) return;
        if (size[u_parent] < size[v_parent]) {
            parent[u_parent] = v_parent;
            size[v_parent] += size[u_parent];
        }
        else {
            parent[v_parent] = u_parent;
            size[u_parent] += size[v_parent];
        }
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
       
        unordered_map<string, int> mapMailNode;
        for(int i = 0; i < n ; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                //if mail is not already mapped
                if(mapMailNode.find(mail) == mapMailNode.end())
                       mapMailNode[mail] = i;
                // if mapped then union the accounts index
                else 
                       unionByRank(i,mapMailNode[mail]);
            }
        }


        vector<string> mergedmail[n];
        for(auto it : mapMailNode) {
            string mail = it.first;
            int node = find(it.second);
            mergedmail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n ; i++) {

            if(mergedmail[i].size() == 0) 
            continue;
        
            //names in sorted order
            sort(mergedmail[i].begin(), mergedmail[i].end());
           
            vector<string> temp;
            string name = accounts[i][0];
            temp.push_back(name);
            for(auto it : mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};