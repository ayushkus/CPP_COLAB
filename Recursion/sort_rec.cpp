#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &arr,int temp)
{
    if (arr.size()==0 || temp>=arr.back())
    {
        arr.push_back(temp);
        return;
    }
    int n=arr.back();
    arr.pop_back();
    insert(arr,temp);
    arr.push_back(n);
}

void sort(vector<int> &arr)
{
    if(arr.size()==1)
        return;
    int tmp=arr.back();
    arr.pop_back();
    sort(arr);
    insert(arr,tmp);
}

int main()
{
    vector<int> arr{5,9,2,1,3};   
    sort(arr);
    for (int i:arr)
        cout<<i<<" ";
    return 0;
}