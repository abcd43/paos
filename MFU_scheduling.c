
#include<stdio.h>
struct node
{
  int pno,frequency;
  }
  
  frames[20];
  int n;
  
  int page_found(int pno)
  {
    int fno;
    for(fno=0;fno<n;fno++)
    {
      if(frames[fno].pno==pno)
        return fno;
     }
   return -1;
 }
 
 
int get_mfu_frame()
{ 
   int selfno=0,fno;
   for(fno=1; fno<n; fno++)
   {
     if(frames[fno].frequency>frames[selfno].frequency)
      selfno=fno;
    }
  return selfno;
}
 
 int get_free_frame()
{ 
   int fno;
   for(fno=0; fno<n; fno++)
   {
     if(frames[fno].pno==-1)
      return(fno);
    }
  return(-1);
}
 
void main()
{
int p_request[]={};
int size=15;
int page_fault=0,i,j,fno;
printf("\nHow many frames :");
scanf("%d",&n);
for(i=0; i<n; i++)
	 {
	   frames[i].pno=-1;
	   frames[i].frequency=0;
	  }
  
  printf("\nPageNo      PageFrames         PageFault");
  printf("\n----------------------------------------------------------");
  for(i=0; i<size; i++)
  {
		j=page_found(p_request[i]);
		if(j==-1) 
     {
       j=get_free_frame();
       if(j==-1)
       
			  j=get_mfu_frame();
			  page_fault++;
			  frames[j].pno=p_request[i];
			  frames[j].frequency++;
			  printf("\n%4d\t",p_request[i]);
			   for(fno=0; fno<n; fno++)
				printf("%4d:%2d\t",frames[fno].pno,frames[fno].frequency);
				printf("YES");
    }
   
  else 
  		{
  		frames[j].frequency++;
		 printf("\n%4d\t",p_request[i]);
		  for(fno=0; fno<n; fno++)
		   printf("%4d:%2d\t",frames[fno].pno,frames[fno].frequency);  
		   printf("NO");
   		}    
   }
	printf("\n-------------------------------------------------------");
	printf("\nNumber of Page Faults=%d",page_fault);
}   
  
             
