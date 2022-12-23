// 1383. Maximum Performance of a Team
// Hard
// 2.7K
// 73
// Companies
// You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

// Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

// The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

// Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
// Output: 60
// Explanation: 
// We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
class Solution {
public:
     class comparator{
        public:
        bool operator()(pair<int,int>&a,pair<int,int>&b)
        {
            return a.second<b.second;
        }
    };
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>speed_effi;
        for(int i=0;i<n;i++)
        {
            speed_effi.push_back({speed[i],efficiency[i]});
        }
        sort(speed_effi.begin(),speed_effi.end(),comparator());
       long long sum=0,result=0;
       priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=n-1;i>=0;i--)
        {
          sum+=speed_effi[i].first;
          pq.push(speed_effi[i].first);
          if(pq.size()>k)
          {
              sum-=pq.top();
              pq.pop();
          }
          result=max(result,sum*speed_effi[i].second);
        }
     return result % 1000000007;
        
    }
};