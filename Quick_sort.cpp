#include<iostream>
using namespace std;

int partition(int A[], int start, int end)
{
	int pivot=A[end];
	int pIndex=start;
	
	for(int i=start; i<end; i++)
	{
		if(A[i]<=pivot)
		{
			swap(&A[i], &A[pIndex]);
			pIndex=pIndex+1;
		}
	}
	swap(&A[pIndex], &A[end]);
	return pIndex;
}
void quick_sort(int A[], int start, int end)
{
	if(start<end)
	{
		int pi=partition(A, start, end);
		quick_sort(A, start, pi-1);
		quick_sort(A, pi+1, end);
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
	quick_sort(arr, 0, s-1);
	print(arr, s);
	return 0;
}
