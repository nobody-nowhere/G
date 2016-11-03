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
	return newNode;
}

void insertVertex(n *hashtable[], int data)
{	int h = data;
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



void insertEdge(n *hashtable[], int v1, int v2)
{	n *tem = hashtable[v1];
	while (tem->next != 0)
		tem = tem->next;
	tem->next = newnode(v2);

	tem = hashtable[v2];
	while (tem->next != 0)
		tem = tem->next;
	tem->next = newnode(v1);
}

int check(n *hashtable[], int from, int to)
{	n *tem = hashtable[from];
   	printf("D");
	if (tem->data == to)
	   return 1;
	while (tem->next != 0)
	{	if (tem->data == to)
	   	{	return 1;
		}
		tem = tem->next;
	}
	return 0;
}

int dfs(n *hashtable[], int from, int to, int *visited)
{	if (check(hashtable, from, to))
   		return 1;
	n *tem = hashtable[from]; int i;
	
	i = tem->data;
	while (tem->next != 0)
	{	if (visited[i] == 0)
	   	{	visited[i] == 1;
			return (dfs(hashtable, i, to, visited));
		}
		tem = tem->next;
	}
	return 0;
}




int main()
{
	n **hashtable =(n **)calloc(MAX, sizeof(n *));
	
	int ele, i;
	int *visited = (int *)calloc(MAX, sizeof(int));
	for (i=0; i<MAX; i++)
	   visited[i] = 0;

	printf("Enter the vertices to be inserted: (0 to stop)");
	while (1)
	{	scanf("%d", &ele);
	   	if (ele == 0)
			break;
		else insertVertex(hashtable, ele);
	}
	printf("Enter the edges to be inserted (Each pair once) (0,0 to stop):");
	int v1,v2;
	while (1)
	{	scanf("%d,%d", &v1, &v2);
	   	if (v1 == 0 && v1 == v2)
		   break;
	    insertEdge(hashtable, v1, v2);
	}

	printf("Depth first search: \n Enter the starting node and ending node in the format from,to: \t");
	int from,to;
	scanf("%d,%d", &from, &to);
	int found = dfs(hashtable, from, to, visited);
	if (found)
		printf("There exists a path. ");
	else printf("Path not found!");
	return 0;
}

