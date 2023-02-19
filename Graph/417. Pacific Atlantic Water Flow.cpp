/*
417. Pacific Atlantic Water Flow
Medium

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
*/

class Solution {
public:
    vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int r,int c,vector<vector<bool>> &vec,vector<vector<int>>& heights,int old)
    {
        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || vec[r][c]==true)
            return;
        if(heights[r][c]>=old)
        {    vec[r][c]=true;
            for(vector<int> dir:directions)
            {
                int nr = r+ dir[0];
                int nc = c+ dir[1];
                dfs(nr,nc,vec,heights,heights[r][c]);
            }
        }
    }

    void solve_pac(vector<vector<int>>& heights,vector<vector<bool>> &pac)
    {
        for(int c=0;c<heights[0].size();c++)
            dfs(0,c,pac,heights,0);
        for(int r=0;r<heights.size();r++)
            dfs(r,0,pac,heights,0);
    }

    void solve_atl(vector<vector<int>>& heights,vector<vector<bool>> &atl)
    {
        for(int c=0;c<heights[0].size();c++)
            dfs(heights.size()-1,c,atl,heights,0);
        for(int r=0;r<heights.size();r++)
            dfs(r,heights[0].size()-1,atl,heights,0);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pac(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> atl(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<int>> res;
        solve_pac(heights,pac);
        solve_atl(heights,atl);
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                vector<int> a{i,j};
                if(pac[i][j]==true && atl[i][j]==true)
                    res.push_back(a);
            }
        }
        return res;
    }
};