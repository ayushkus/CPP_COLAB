#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int,vector<int>> hp;
        int currfuel=startFuel;
        int stop=0;
        int mxfuel;
        for(vector<int> s:stations)
        {
            while (currfuel<s[0])
            {
                if(hp.size()==0)
                    return -1;
                if(currfuel>=target)
                    return stop;
                mxfuel=hp.top();
                currfuel+=mxfuel;
                hp.pop();
                stop++;
            }
            hp.push(s[1]);
        }
        while(currfuel<target)
        {
            if(hp.size()==0)
                return -1;
            mxfuel=hp.top();
            currfuel+=mxfuel;
            hp.pop();
            stop++;
        }
        return stop;
    }
};

int main() 
{
	int target =100;
    int startFuel=10;
    vector<vector<int>> stations {{10,60},{20,30},{30,30},{60,40}};
	int ans = Solution::minRefuelStops(target,startFuel,stations);
	cout << ans << endl;
    /*
    expected output 2
    */
	return 0;
}