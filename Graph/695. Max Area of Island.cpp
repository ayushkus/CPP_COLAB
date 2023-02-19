/*
695. Max Area of Island
Medium
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*/

class Solution {
public:
    vector<vector<int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
    int solve(int r,int c, vector<vector<int>> &grid)
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!=1)
            return 0;
        int a=0;
        grid[r][c]=2;
        for(vector<int> dir : directions)
        {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || grid[nr][nc]!=1)
                continue;
            else
                a+= 1+solve(nr,nc,grid);
        }
        return a;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int c = 1+solve(i,j,grid);
                    max_c = max(max_c,c);
                }    
                
            }
        }
        return max_c;
    }
};