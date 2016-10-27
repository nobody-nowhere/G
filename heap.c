#include <stdio.h>

void heapify(int *arr, int n, int i)
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
{	int i;	
	for (i= n/2-1; i>=0; i--)
		heapify(arr, n, i);
	for (i=n-1; i>=0; i--)
	{	int tem = arr[0];
		arr[0] = arr[i];
		arr[i] = tem;
		heapify(arr, i, 0);
	}
}





int main()
{
	int arr[300], size=0, ele;
	printf("Enter the elements: (Press 0 to stop)");
	while (1)
	{	
		scanf("%d", &ele);
		if (ele == 0)
			break;
		arr[size++] = ele;
	}		
	heapsort(arr, size);
	int i;
	for (i=0; i<6; i++)
		printf("%d ", arr[i]);
}

