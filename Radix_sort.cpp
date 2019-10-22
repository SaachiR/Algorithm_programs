#include<iostream>
using namespace std;
void radix_sort(int A[],int size,int max)
{
	int C[10],B[size],rem=10,quo=1;
	for(int p=1;p<=max;p++)
	{
	
		if(p!=1)
		{
			rem=rem*10;
			quo=quo*10;
		}
	
		for(int i=0;i<=9;i++)
		{
			C[i]=0;
		}
	
		for(int j=1;j<=size;j++)
		{
			C[(A[j]%rem)/quo] = C[(A[j]%rem)/quo]+1; 
		}
	
		for(int i=1;i<=9;i++)
		{
			C[i]=C[i]+C[i-1];
		}
		
		for(int j=size;j>=1;j--)
		{
			B[C[(A[j]%rem)/quo]]=A[j];
			C[(A[j]%rem)/quo]--;
		}
		for(int i=1;i<=size;i++)
            {
                A[i]=B[i];
            }
	}
	
}
int main()
{
	int size,arr[30],k=0;
	cout<<"Enter size : ";
	cin>>size;
	cout<<"Enter elements : ";
	for(int i=1;i<=size;i++)
	{
		cin>>arr[i];
		if(k<arr[i])
			k=arr[i];
	}
	cout<<"You entered : ";
	for(int i=1;i<=size;i++)
	{
		cout<<arr[i] <<" ";
	}
	int count=0;
    while(k>0)
    {
       	k=k/10;
       	count++;
	}
    radix_sort(arr,size,count);
    cout<<endl;
	cout<<"Sorted array : ";
	for(int i=1;i<=size;i++)
	{
		cout<<arr[i] <<" ";
	}
	

}

