
#include<stdio.h>
struct frmnode
{
  int pno,counter;
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
  
  
int get_mru_frame()
{
  int mrufno=0,fno;
   for(fno=1; fno<n; fno++)
   {
   if(frames[fno].counter>frames[mrufno].counter)
   mrufno=fno;
   }
  return mrufno;
}    

 
void main()
{
int p_request[]={5,8,10,14,10,9,5,10,8,5,1,10,9,12,10};
int size=sizeof(p_request)/4,currtime;

int page_fault=0,i,j,fno;
printf("\nHow many frames :");
scanf("%d",&n);
for(i=0; i<n; i++)
	 {
	   frames[i].pno=-1;
	  }
  
  printf("\nPageNo      PageFrames         PageFault");
  printf("\n----------------------------------------------------------");
  currtime=0;
  for(i=0; i<size; i++)
  {
		j=page_found(p_request[i]);
		if(j==-1) 
     {
       page_fault++;
       j=get_free_frame();
       if(j==-1)
       
			  j=get_mru_frame();
			  frames[j].pno=p_request[i];
			  frames[j].counter=currtime;
			  printf("\n%4d\t",p_request[i]);
			   for(fno=0; fno<n; fno++)
				printf("%4d:%2d\t",frames[fno].pno,frames[fno].counter);
				printf("YES");
    }
   
  else
  		{
  		frames[j].counter=currtime;
		 printf("\n%4d\t",p_request[i]);
		  for(fno=0; fno<n; fno++)
		   printf("%4d:%2d\t",frames[fno].pno,frames[fno].counter);  
		   printf("NO");
   		} 
   		currtime++;        
   }
	printf("\n-------------------------------------------------------");
	printf("\nNumber of Page Faults=%d",page_fault);
}   
  
             
