/*
https://leetcode.com/problems/reduce-array-size-to-the-half/description/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int minSetSize(vector<int>& arr) {
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
int main() 
{
	vector<int> arr {3,3,3,3,5,5,5,2,2,7};
	int ans = Solution::minSetSize(arr);
	cout << ans << endl;
	return 0;
}