class Solution {
public:
    int m,n;
    
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        if(r<0||r>=m||c<0||c>=n||image[r][c]!=oldColor) return;
        image[r][c] = newColor;
        dfs(image, r+1, c, oldColor, newColor);
        dfs(image, r-1, c, oldColor, newColor);
        dfs(image, r, c+1, oldColor, newColor);
        dfs(image, r, c-1, oldColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        
        if(image[sr][sc] == color) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};