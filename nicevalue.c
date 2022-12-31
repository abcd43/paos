
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 void main()
 {
  int pid,cnice,pnice;
  pid=fork();
  
  if(pid==0)
  {
  printf("\nI am child process and my pid=%d",getpid());
  cnice=nice(-3);
  printf("\n Low nice value=%d i.e high priority to child process",cnice);
 
  }
  
  
   else if(pid>0)
  {
   printf("\nI am parent process and my pid=%d",getpid());
   pnice=nice(3);
   printf("\n High nice value=%d i.e low priority to parent process",pnice);
   }
   
   
   else if(pid<0)
   {
   printf("\nUnable to create child process");
   exit(0);
   }
 }
   
