// 1337. The K Weakest Rows in a Matrix
// Easy
// 3K
// 174
// Companies
// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

// Example 1:

// Input: mat = 
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]], 
// k = 3
// Output: [2,0,3]
// Explanation: 
// The number of soldiers in each row is: 
// - Row 0: 2 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 2 
// - Row 4: 5 
// The rows ordered from weakest to strongest are [2,0,3,1,4].
class Solution {
public:
     class comparator
     { public:
         bool operator()(pair<int,int>&a,pair<int,int>&b)
     {
         if(a.second==b.second)
         {
             return a.first<b.first;
         }
         return a.second<b.second;
     }     
     };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>pq;
        map<int,int>mp;
        int index=0;
        for(auto elements:mat)
        {
            int count=0;
            for(int j=0;j<elements.size();j++)
            {
                if(elements[j]==1)
                count++;
            }
            mp[index++]=count;
          
        }
        for(auto i:mp)
        {
         pq.push(i);
         if(pq.size()==k+1)
         {
             pq.pop();
         }
        }
        vector<int>ans;
        while(!pq.empty())
        { int annn=pq.top().first;
            ans.push_back(annn);
            pq.pop();
        }     
        reverse(ans.begin(),ans.end());
        return ans;
    }
};