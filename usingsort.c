
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
			int arr[20],n,i,j,temp,pid;
			printf("\nEnter the number of elements : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				 printf("\nEnter the elements :");
				 scanf("%d",&arr[i]);
			}
			 
			pid=fork();
			if(pid>0)	
			{	
				for(i=0; i<n; i++)
				{
					for(j=i+1; j<n; j++)
					{	
						int temp;
						if(arr[i]>arr[j])
						{
							temp=arr[i];
							arr[i]=arr[j];
							arr[j]=temp;
						}
					}
				}    
				for(i=0; i<n; i++)
				{
					 printf("\nParent process sort: %d\n",arr[i]);
				}
			   wait(0);
			}
			  
			else if(pid==0)
			{
			  
				for(i=1; i<=n; i++)
				{
						temp=arr[i];
						j=i-1;
						
						 while(arr[j]>temp && j>=0)
							 {
							   arr[j+1]=arr[j];
							   j--;
							   }
						   
						   arr[j+1]=temp;
				   }
				 
				
				 for(i=0; i<n; i++)
				 printf("\nChild process sort: %d",arr[i] );
				
				 }
				
				else if(pid<0)
				{
				printf("\nUnable to create child process");
				exit(0);
				}
}

     
     
     
     
      
