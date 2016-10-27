#include <stdio.h>

void heapfiy(int *arr, int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if (arr[l] > arr[largest] && l < n)
		largest = l;
	if (arr[r] > arr[largest] && r < n)
		largest = r;
	
	if (largest != i)
	{	int tem = arr[largest];
		arr[largest] = arr[i];
		arr[i] = tem;
		heapify(arr, n, largest);
	}
}

void heapsort(int *arr, int n)
{	
	for (i= n/2-1; i>=0; i--)
		heapify(arr, n, i);
	for (int i=n-1; i>=0; i--)
	{	int tem = arr[0];
		arr[0] = arr[i];
		arr[i] = tem;
		heapify(arr, i, 0);
	}
}





int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = 6;
	heapsort(arr, 6);
	for (int i=0; i<6; i++)
		printf("%d ", arr[i]);
}

