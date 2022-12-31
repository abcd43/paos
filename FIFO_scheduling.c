#include<stdio.h>
struct frmnode
{
  int pno;
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
  
  
int get_fifo_frame()
{
  static int fno=-1;
  fno=(fno+1)%n;
  return(fno);
}
 
int main()
{
int p_request[]={};
int size=sizeof(p_request)/4;

int page_fault=0,i,j,fno;
printf("\nHow many frames :");
scanf("%d",&n);
for(i=0; i<n; i++)
	 {
	   frames[i].pno=-1;
	  }
  
  printf("\nPageNo      PageFrames         PageFault");
  printf("\n----------------------------------------------------------");
  for(i=0; i<size; i++)
  {
		j=page_found(p_request[i]);
		if(j==-1) 
     {
       page_fault++;
       j=get_free_frame();
       if(j==-1)//no free frame -do page replacement
       
			  j=get_fifo_frame();
			  frames[j].pno=p_request[i];//load page in frame
			  printf("\n%6d\t",p_request[i]);
			   for(fno=0; fno<n; fno++)
				printf("%6d\t",frames[fno].pno);
				printf("YES");
    }
   
  else //page found in frame j
  		{
		 printf("\n%6d\t",p_request[i]);
		  for(fno=0; fno<n; fno++)
		   printf("%6d\t",frames[fno].pno);  
		   printf("NO");
   		}            
   }//for
	printf("\n-------------------------------------------------------");
	printf("\nNumber of Page Faults=%d",page_fault);
}   
  
             
