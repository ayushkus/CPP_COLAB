#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{ for(int i=0;i<n-1;i++)
    { for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    return; }
int main()
{   int arr[50];
    int n;
    cout<<"Enter size of the array :"<<endl;
    cin>>n;
    cout<<"Enter the element in the array :"<<endl;
    for(int i=0;i<n;i++)
    {   cout<<i+1<<" Element are : ";
        cin>>arr[i];
    }
    bubblesort(arr,n);
    cout<<"Sorted Array ";
    for(int j=0;j<n;j++)
    {
        
        cout<<arr[j]<<",";
    }


}