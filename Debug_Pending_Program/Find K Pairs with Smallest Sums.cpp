/*
373. Find K Pairs with Smallest Sums
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/

class Solution {
    struct comparator{
        bool operator()(pair<int,vector<int>> a,pair<int,vector<int>> b)
        {
            return b.first>a.first;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,comparator> hp;
        vector<vector<int>> res;
        for(int i:nums1)
        {
            for(int j:nums2)
            {
                vector<int> v{i,j};
                pair<int,vector<int>> p;
                p.first=i+j;
                p.second=v;
                hp.push(p);
                if(hp.size()>k)
                    hp.pop();
            }
        }
        while(!hp.empty())
        {
            vector<int> tmp=hp.top().second;
            hp.pop();
            res.push_back(tmp);
        }
        return res;
    }
};