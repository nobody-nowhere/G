//THIS PROGRAM IMPLEMENTS DOUBLE HASHING
#include <stdio.h>
int a[17],count=1;
void insert(int b,int n)
{
	int flag=0,i,probe,offset;
    
    for(i=0;i<=16;i++)
     { 	if(a[i]!=-1)
        flag++;       
        }
     if(flag==16)
     printf("\t the table is full!!!\n");
     else
     {
     	probe=b%17;
     	offset=n-(b%n);
     	while(a[probe]!=-1&&a[probe]!=-1000)
     		probe=(probe+offset)%17;

     	a[probe]=b;

     }
}
void deletion(int b,int n)
{
	 int i,probe,flag=0;
    probe=b%17;
    int offset=n-(b%n);
    while(a[probe]!=-1)
   {  if(a[probe]==b)
       {
       	flag=1;
       	break;
       }	
       probe=(probe+offset)%17;
    }
    if(flag==1)
    {for(i=probe;a[i]==b;i++)
    	{ 
    		a[i]=-1000;
    		count--;
    	}
    }
    else 
    	printf("\t sorry!!! the element does not exist!!!!\n");
   
}
void search(int b,int n)
{
	int flag=0,i,probe;
	probe=b%17;
    int offset=n-(b%n);
    while(a[probe]!=-1)
    {
    	  if(a[probe]==b)
    	  {
    	  	printf("\t yes!!! the element is there!!!\n");
    	  	flag=1;
    	  	break;
    	  }
       probe=(probe+offset)%17;
    
    }
    if(flag==0)
    	printf("\t sorry!!! the element is not found!!!\n");
	
}
void main()
{
	int j,ch2,i,k,ch1=1;
   for(i=0;i<=16;i++)
   	a[i]=-1;
   printf("\t enter the number of elements to be inserted:");
   	 scanf("%d",&j);  
   while(ch1==1)
   {
   	 printf("\t MENU \n \t 1.INSERT THE ELEMENT INTO HASH TABLE \n");
   	 printf("\t 2.DELETE THE ELEMENT FROM THE HASH TABLE \n");
   	 printf("\t 3.SEARCH FOR AN ELEMENT\n");
   	 printf("\t enter your choice:");
     scanf("%d",&ch2);
     if(ch2==1)
   	 {  
   	 	if(count<=j)
   	 	{printf("\t enter the key to be inserted:");
        scanf("%d",&k);
     
         insert(k,j);
         count++;
       printf("\t the hash table:");
      for(i=0;i<=16;i++)
     {
     	if(a[i]!=-1 && a[i]!=-1000)
     		printf("\t %d",a[i]);
     	else
     		printf("\t $");//marking the empty slots by '$'
     }
 }
     else 
       printf("\t sorry!!!! you have exceeded the maximum number of elements to be inserted!!!\n");
}
     else if(ch2==2)
     {
     	printf("\t enter the element to be deleted:");
     	scanf("%d",&k);
     	deletion(k,j);
         printf("\t the hash table:");
     for(i=0;i<=16;i++)
     {
     	if(a[i]!=-1&&a[i]!=-1000)
     		printf("\t %d",a[i]);
     	else if(a[i]==-1)
     		printf("\t $");//marking the empty slots by '$'
        else 
        	printf("\t X");// marking the deleted element by a tombstone
     }	
     }
     else
     {
     	printf("\t enter the element to be searched:");
     	scanf("%d",&k);
     	search(k,j);
     }
     printf("\n");
     printf("\t do you want to continue(1/0)?:");
     scanf("%d",&ch1);

   }

}
