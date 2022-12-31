
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 void main()
 {
  int pid;
  pid=fork();
  
  if(pid==0)
  {
  printf("\nI am child process and my pid=%d",getpid());
  printf("\n My parent pid is=%d",getppid());
  }
  
  else if(pid>0)
  {
   printf("\nI am parent process and my pid=%d",getpid());
   printf("\n My child pid is=%d",pid);
   }
   
  else if(pid<0)
   {
   printf("\nUnable to create child process");
   exit(0);
   }
 }
   
