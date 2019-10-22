#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
void bucket_sort(int A[], int size)
{
	int i, j;
	vector <int> B[size];
	int max=A[0];
	for(i=0; i<size; i++)
	{
		if(max<A[i])
		{
			max=A[i];
		}	
	}
	int count=0;
	while(max>0)
	{
		max=max/10;
		count++;
	}
	int d=pow(10,count);
	for(i=0; i<size; i++)
	{
		int bi=A[i]/d;
		B[bi].push_back(A[i]);
	}
	for(i=0; i<size; i++)
	{
		sort(B[i].begin(), B[i].end());
	}
	int index = 0;
    for (i = 0; i <size; i++)
        {
			for (j = 0; j < B[i].size(); j++)
          		{
				 	A[index++] = B[i][j];
				}
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
	bucket_sort(arr, s);
	print(arr, s);
	return 0;
}
