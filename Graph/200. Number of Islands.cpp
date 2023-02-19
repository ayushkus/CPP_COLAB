/*
200. Number of Islands
Medium
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    
    vector<vector<int>> directions {{1,0},{0,1},{-1,0},{0,-1}};    
    void dfs(int r,int c,vector<vector<char>>& grid)
    {
        if(r<0 ||c<0 ||r>=grid.size() ||c>=grid[0].size() || grid[r][c]!='1')
            return;
        grid[r][c]='2';
        for(vector<int> dir:directions)
        {  
            int nr = r + dir[0];
            int nc = c + dir[1];
            dfs(nr,nc,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    count++;
                }
                
            }
        }
        return count;
    }
};