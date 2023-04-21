/*
Problem Statement
Suggest Edit
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, 'C' -
1) in the grid. Each of them can move from their current cell to the cells just below them.
When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.
If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j − 1) or (i + 1, j + 1). They will always stay inside the 'GRID'.
Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.
*/

#include <bits/stdc++.h>
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int chocl;
    if (j1 == j2)
        chocl = grid[i][j1];
    else
        chocl = grid[i][j1] + grid[i][j2];
    int up = -1e9;
    int ldiag = -1e9;
    int rdiag = -1e9;
    int maxi = -1e9;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (i + 1 < r && j1 + x < c && j1 + x >= 0 && j2 + y < c && j2 + y >= 0)
                maxi = max(maxi, chocl + solve(i + 1, j1 + x, j2 + y, r, c, grid, dp));
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return solve(0, 0, c - 1, r, c, grid, dp);
}