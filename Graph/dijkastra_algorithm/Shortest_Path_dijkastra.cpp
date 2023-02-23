// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
// You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

// Example:
// Input:
// n = 5, m= 6
// edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
// Output:
// 1 4 3 5
// Explaination:
// Shortest path from 1 to n is by the path 1 4 3 5

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes n vertex and m edges and vector of edges having weight as inputs and returns the shortest path between vertex 1 to n.

// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n)

// Constraint:
// 2 <= n <= 105
// 0 <= m <= 105
// 0<= a, b <= n
// 1 <= w <= 105
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj;
        for(int i=0;i<=n;i++)
        {
            vector<pair<int,int>>v1;
            adj.push_back(v1);
        }
        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        dis[1]=0;
        pq.push({0,1});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int ndis=it.second;
                int nnode=it.first;
                if(dist+ndis<dis[nnode])
                {  
                    dis[nnode]=dist+ndis;
                    pq.push({dis[nnode],nnode});
                    parent[nnode]=node;
                }
            }
        }
        vector<int>ans;
        if(dis[n]==1e9)
        {
            ans.push_back(-1);
            return ans;
        }
        int node=n;
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};