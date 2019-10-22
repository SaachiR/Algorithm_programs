#include<iostream>
using namespace std;
void print(int arr[],int n)
{
     cout<<endl;
     for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
void count_sort(int a[],int n,int k)
{
    int count[k];
    for(int i=0;i<k;i++)
    count[i]=0;
    for(int i=0;i<n;i++)
     count[a[i]]+=1;
     
    int c[k];
    c[0]=count[0];
    for(int i=1;i<k;i++)
    c[i]=count[i]+c[i-1];
    
    int array[n];
    for(int i=n-1;i>=0;i--)
    {
     array[c[a[i]]-1]=a[i];
     c[a[i]]--;
    }
    cout<<"\nyour sorted array is:";
    print(array,n);
}
int main()
{
    int n,k;
    cout<<"enter the number of elements you want:";
    cin>>n;
    cout<<"enter range of element:";
    cin>>k;
    k=k+1;
    int a[n];
    cout<<"enter the elements:";
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(a[i]>k)
    {
     cout<<"please enter elements in range!";
     return 0;
    }
    }
    
    count_sort(a,n,k);
    return 0;
}


