#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void selection_sort(int A[], int size)
{
	int i, j, min;
	for(i=0; i<size-1; i++)
	{
		min=i;
		for(j=i+1; j<size; j++)
		{
			if(A[j]<A[min])
			{
				min=j;
			}
		}
		swap(&A[min], &A[i]);
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
	selection_sort(arr, s);
	print(arr, s);
	return 0;
}
