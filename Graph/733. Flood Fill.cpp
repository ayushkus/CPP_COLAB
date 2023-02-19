/*
733. Flood Fill
Easy
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
*/

class Solution {
public:
    vector<vector<int>> directions {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& image,int r,int c,int color,int old)
    {
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c]!=old)
            return;
        image[r][c]=color;
        for(vector<int> dir:directions)
        {
            int nr=r+dir[0];
            int nc=c+dir[1];
            dfs(image,nr,nc,color,old);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int old=image[sr][sc];
        dfs(image,sr,sc,color,old);
        return image;
    }
};