#include<iostream>
using namespace std;
void insertion_sort(int A[], int size)
{
	int i, j, key;
	for(int i=1; i<size; i++)	
	{
		key=A[i];
		j=i-1;
		while(j>=0 && A[j]>key)
		{
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=key;
	}
}
void print(int A[], int size)
{
	cout<<"The sorted array is:\n";
	
	for(int i=0; i<size; i++)
	{
		cout<<A[i]<<"  ";
	}
}
int main()
{
	int s;
	cout<<"Enter the size of th array ";
	cin>>s;
	int arr[100];
	cout<<"Enter the elements of your array ";
	for(int i=0; i<s; i++)
	{
		cin>>arr[i];
	}
	insertion_sort(arr, s);
	print(arr, s);
	return 0;
}
