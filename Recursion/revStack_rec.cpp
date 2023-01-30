#include<bits/stdc++.h>
using namespace std;

void ins(stack<int> &st,int k)
{
    if(st.size()==0)
    {
        st.push(k);
        return;
    }
    int tmp=st.top();
    st.pop();
    ins(st,k);
    st.push(tmp);

}


void rev(stack<int> &st)
{
    if(st.size()==1)
        return;
	int k=st.top();
    st.pop();
    rev(st);
    ins(st,k);
}

int main()
{
    stack<int> st;
    st.push(2);   
    st.push(10);  
    st.push(5);  
    st.push(1);  
    st.push(6);  
    rev(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}