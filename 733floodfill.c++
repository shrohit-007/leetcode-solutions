class Solution {
public:
    void dfs(vector<vector<int>>&image,int i,int j,int color, int root)
    {
        if(i<0 or i>=image.size() or j<0 or j>=image[0].size() or image[i][j]!=root)
        {
            return ;
        }
        image[i][j]=color;
        dfs(image,i+1,j,color,root);
        dfs(image,i-1,j,color,root);
        dfs(image,i,j+1,color,root);
        dfs(image,i,j-1,color,root);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc])
            return image;
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};
