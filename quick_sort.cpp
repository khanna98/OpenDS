#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=low-1,j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
int quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}
void displayArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main(int argc,char *argv[])
{
	int i;
	int arr[argc-1];
	for(i=0;i<argc-1;i++)
	{
		arr[i]=(atoi)(argv[i+1]);
	}
	quickSort(arr,0,argc-2);
	displayArray(arr,argc-1);
}
