#include <stdio.h>
#define MAX 10

struct Node
{	int data;
	int key;
};

typedef struct Node n;

int hash(int data)
{	return key%MAX;
}

void htinit(n* ht)
{	int i = 0;
	for (i=0; i<MAX; i++)
	{	ht[i] -> data = 0;
		ht[i] -> key = i;
	}
}


int main()
{
	n ht[10]; int ele;
	htinit(ht);
	printf("Enter the data to be inserted into hash table: ");
	while(1)
	{	scanf("%d", &ele);
		if (ele == 0)
			break;
				
