#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 		heapify(arr, n, largest);
    }
}
 

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
	for (int i=n-1; i>=0; i--)
    {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
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
	heap_sort(arr, s);
	print(arr, s);
	return 0;
}
