/*
https://leetcode.com/problems/reduce-array-size-to-the-half/description/
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        priority_queue<int,vector<int>> hp;
        for(int i:arr)
            mp[i]++;
        int count;
        int size=n;
        for(pair<int,int> p:mp)
            hp.push(p.second);
        for(count=0;!hp.empty();count++)
        {
            if(size<=(n/2))
                return count;
            size-=hp.top();
            hp.pop();
        }
        if(size<=(n/2))
            return count;
        return 0;
    }
};