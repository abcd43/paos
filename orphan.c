

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 void main()
 {
  int pid;
  pid=fork();
  
  if(pid>0)
  {
   printf("\nI am parent process");
   printf("\n My  pid is=%d",getpid());
   }
   
   
   else if(pid==0)
  {
  printf("\nI am child process");
  sleep(30);
  printf("\n My parent process pid is=%d",getppid());
  }
  
  
  
  else if(pid<0)
   {
   printf("\nUnable to create  process");
   exit(0);
   }
    }
  
  
