/*
347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/



class Solution {
public:
    struct comparator{
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            return b.second < a.second ;
        }           
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> hp;
        vector<int> res;
        for(int i:nums)
            mp[i]++;
        for(pair<int,int> p:mp)
        {
            hp.push(p);
            if(hp.size()>k)
                hp.pop();
        }
        for(int i=0;i<k;i++)
        {
            pair<int,int> p=hp.top();
            hp.pop();
            res.push_back(p.first);
        }
        return res;
    }
};