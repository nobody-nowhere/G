#include <stdio.h>
#include <stdlib.h>



void printit(int **arr , int n)
{
   printf("\n\nmatrix\n\n");
   int i=0,j=0;
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
	 printf(" %d ",arr[i][j]);
      printf("\n");
   }
   printf("\n\n\n");
}

void printvis(int *vis , int n)
{
   int i=0;
   printf("\n\nvisited array : ");
   for(i=0;i<n;i++)
   {
      printf(" %d ",vis[i]);
   }
   printf("\n\n");
}//print visited

int allvis(int *vis , int n)
{
   int i=0;
   for(i=0;i<n;i++)
   {
      if(vis[i]==0)
	 return 0;
   }
   return 1;
}

int fin[20][20];

int dfs(int n , int **arr , int f , int t , int *vis,int **fin)
{
   printf("%d\n\n",f);
   vis[f] = 1;
   int i=0;
   for(i=0;i<n;i++)
   {
      if(i==f)
	 continue;
      if(arr[f][i]==1 && vis[i] == 0)
      {
	 fin[f][i] = 1;
	 fin[i][f] = 1;
	 dfs(n,arr,i,t,vis,fin);
      }
   }
   return 0;

}//dfs(n,arr,f,t)

void main()
{
   int n=0;
   printf("enter the no. of nodes : ");
   scanf("%d",&n);
   int **arr = (int **)malloc(n*sizeof(int *));
   int **fin = (int **)malloc(n*sizeof(int *));
   int i=0;
   for(i = 0 ; i<n; i++)
   {
      arr[i] = (int *)malloc(n*sizeof(int));
      fin[i] = (int *)malloc(n*sizeof(int));
   }
   int j=0 , k=0 , g=0;
   
   int *vis = (int *)malloc(n*sizeof(int));

   for(j=0;j<n;j++)
      for(k=0;k<n;k++)
	 arr[j][k] = 0;

   j=0;
   k=0;
   i=0;
   printf("Enter the edges. (0,0) to end.");
   scanf("%d,%d", &j, &k);
   while ((k!=0) || (j!=k))
   {   arr[j][k] = 1;
       arr[k][j] = 1;
       printf("Added. \n\n");
       scanf("%d,%d", &j, &k);
   }
   printf("Depth first search: \n\n");
   j=0; k=n-1;
   for(g=0;g<n;g++)
   vis[g]=0;
   vis[j] = 1;
   k = dfs(n,arr,j,k,vis,fin);
   printit(arr,n);
}//main()

