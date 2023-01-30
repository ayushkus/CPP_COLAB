#include<bits/stdc++.h>
using namespace std;

void del(stack<int> &st,int k)
{
	if(k==1)
	{
		st.pop();
		return;
	}
	int tmp=st.top();
	st.pop();
	del(st,k-1);
	st.push(tmp);
}

void del_mid(stack<int> &st)
{
	int n=st.size();
    if(n==0)
        return;
	int k=(n/2)+1;
	del(st,k);
}

int main()
{
    stack<int> st;
    st.push(2);   
    st.push(10);  
    st.push(5);  
    st.push(1);  
    st.push(6);  
    del_mid(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}