#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &arr,int temp)
{
    if (arr.size()==0 || temp>=arr.top())
    {
        arr.push(temp);
        return;
    }
    int n=arr.top();
    arr.pop();
    insert(arr,temp);
    arr.push(n);
}

void sort(stack<int> &arr)
{
    if(arr.size()==1)
        return;
    int tmp=arr.top();
    arr.pop();
    sort(arr);
    insert(arr,tmp);
}

int main()
{
    stack<int> arr;
    arr.push(2);   
    arr.push(10);  
    arr.push(5);  
    arr.push(1);  
    arr.push(6);  
    sort(arr);
    while(!arr.empty())
    {
        cout<<arr.top()<<" ";
        arr.pop();
    }
    return 0;
}