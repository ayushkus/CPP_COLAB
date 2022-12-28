#include<bits/stdc++.h>
using namespace std;
class Solution {
    struct comparator{
        bool operator()(pair<char,int> &a,pair<char,int> &b)
        {
            return a.second<b.second;
        }
    };
public:
    static string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<char,int>,vector<pair<char,int>>,comparator> hp;
        for(char ch:s)
            mp[ch]+=1;
        for(pair<char,int> p:mp)
            hp.push(p);
        string res="";
        while(!hp.empty())
        {
            res+=string(hp.top().second,hp.top().first);
            hp.pop();
        }
        return res;
    }
};
int main() 
{
	string s = "tree";
	string ans = Solution::frequencySort(s);
	cout << ans << endl;
	return 0;
}