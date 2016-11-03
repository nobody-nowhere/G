#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Node
{	int data;
   	struct Node *next;
};

typedef struct Node n;


int hash(int data)
{	return data % MAX;
}

n * newnode(int data)
{	n *newNode = (n *)malloc(sizeof(n *));
   	newNode->data = data;
	newNode->next = 0;
}

void insert(n *hashtable[], int data)
{	int h = hash(data);
   	if (hashtable[h] == 0)
	{	hashtable[h] = newnode(data);
	   	return;
	}
	else 
	{	n *tem = hashtable[h];
	   	while (tem->next != 0)
		{	tem = tem->next;
		}
		tem->next = newnode(data);
	}
}

int search(n *hashtable[], int data)
{
   	int h = hash(data);
	if (hashtable[h] == 0)
		return -1;
	n *tem = hashtable[h];
	while (tem->next != 0)
	{	if (tem->data == data)
	   		return 0;
	   	tem = tem->next;
	}
	return -1;
}
	   	


int main()
{
	n **hashtable =(n **)calloc(MAX, sizeof(n *));

   	int ele;
	printf("Enter the elements to be inserted: (0 to stop)");
	while (1)
	{	scanf("%d", &ele);
	   	if (ele == 0)
			break;
		else insert(hashtable, ele);
	}
	printf("Enter the element to be searched for: ");
	scanf("%d", &ele);
	int found = search(hashtable, ele);
	if (found == 0)
	{	printf("Element found!");
	}
	else printf("Element not found.");
	return 0;
}

