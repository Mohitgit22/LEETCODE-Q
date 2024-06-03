class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        int startcolor = image[sr][sc];
        if (startcolor == color) return image;

        image[sr][sc] = color;

        queue<pair<int, int>> que;

        que.push({sr, sc});

        int dx[4] = { 0, 0, 1, -1};
        int dy[4] = { 1, -1, 0, 0};

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for(int i = 0; i < 4; i++) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(newx < 0 || newy < 0 || newx >= m || newy >= n || image[newx][newy] != startcolor )
                     continue;
                    image[newx][newy] = color;
                    que.push({newx, newy});
                }
            }
        }

        return image;
    }
};