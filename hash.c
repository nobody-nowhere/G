#include <stdio.h>
#define MAX 10

struct Node
{	int data;
	struct Node *next;
};

typedef struct Node n;

n ht[10];

int hash(int data)
{	return data%MAX;
}


void insert(int ele)
{	int hele = hash(ele);
	n *tem;
	if (ht[hele] -> next == 0)
		ht[hele] -> data = ele;
	else
	{	n *a;
		a -> data = ele;
		a -> next = 0;
		tem = ht[hele];
		while (tem -> next != 0)
		{	tem = tem -> next;
		}
		tem -> next = a;	
	}
}

int search(int ele)
{	int hele = hash(ele); int found = 0;
	n *tem;
	if ((ht[hele]) -> data == 0)
		return 0;
	else
	{	if ((ht[hele]) -> next == 0)
		{	if (ht[hele] -> data == ele)
			{	return 1;
			}
		}
		else
		{	while (tem -> next != 0)
			{	
				tem = tem -> next;
				if (tem -> data == ele)
				{
					return 1;
				}
			}
			return 0;
		}
	}
}
					
	

int main()
{
	printf("DASDAS");
	int i,ele;
	for (i=0;  i < 10; i++)
	{	
		printf("DASDASD");
		ht[i] -> next = 0;
		ht[i] -> data = 0;
	}
	printf("Enter the data to be inserted into hash table: ");
	while(1)
	{	scanf("%d", &ele);
		if (ele == 0)
			break;
		insert(ele);
	}
	printf("Enter the element to be searched for: ");
	scanf("%d", &ele);
	if(search(ele))
		printf("Element found!");
	else
		printf("Element not found.");
}
	
						
