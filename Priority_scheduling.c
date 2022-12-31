
#include<stdio.h>
#include<stdlib.h>

struct proc_info
{
		int atime;
		int cpub;
		int pid;
		int priority;
} proc[20],temp;

struct ganttchart
{
		int stime;
		int pid;
		int etime;
}gchart[20];

int i,j,n,ctime,gi=0,wtime[20],ttime[20];

void getprocs();
void start();
void dispgchart();
void addgchart(int);
void disptimes();
int finished();

int main()
{

		getprocs();
		ctime=0; 	
		start();
		dispgchart();
		disptimes();
}

void getprocs()
{
		printf("\n How  many processes :"); 
		scanf("%d",&n);
		printf("\n PID\tATIME \tCPUB \tPRIORITY\n");
		for(i=1;i<=n; i++)
		{
				scanf("%d%d%d%d",&proc[i].pid,&proc[i].atime,&proc[i].cpub,&proc[i].priority);
		}
		for(i=1;i<=n;i++)
		{
				for(j=i+1;j<=n;j++)
				{
						if(proc[i].priority<proc[j].priority)
						{
								temp=proc[i];
								proc[i]=proc[j];
								proc[j]=temp;
						}
				}
		}
		for(i=1;i<=n;i++)
		{
			printf("\n %d\t%d\t%d\t%d",proc[i].pid,proc[i].atime,proc[i].cpub,proc[i].priority);
		}
}

void start()
{
		int pid;
		
		while(!finished())
      {
		for(i=1;i<=n;i++)
		{
		   if(proc[i].atime<=ctime&&proc[i].cpub!=0)
             {
				wtime[i]=ctime-proc[i].atime;
				addgchart(proc[i].pid);
				while(proc[i].cpub!=0)
				{
						ctime++;			
						proc[i].cpub--;
						if(proc[i].cpub==0)	
						{
								printf("\n Proc %d completed at time %d..",proc[i].pid,ctime);
								ttime[i]=ctime-proc[i].atime;
								break;
						}
				}
		}
	 }
 }		
		gchart[gi].etime=ctime;
}

void addgchart(int pid)
{
		gchart[++gi].pid=pid;
		gchart[gi].stime=ctime;
		gchart[gi-1].etime=gchart[gi].stime;	
}


int finished()
 {
   for(i=1;i<=n; i++)
     {
       if(proc[i].cpub!=0)
        return 0;
     }
  return 1;
}


void dispgchart()
{
 printf("\n");
  for(i=1; i<=gi; i++)
    printf("|-----");
    printf("|\n");
    
    for(i=1;i<=gi;i++)
    printf("| %d ",gchart[i].pid);
    printf("|\n");
    
    for(i=1; i<=gi; i++)
    printf("|-----");
    printf("|\n");
    
    for(i=1;i<=gi;i++)
    printf("| %d ",gchart[i].stime);   
    
    printf("%d\n",gchart[gi].etime);
}

 void disptimes()
 {
 int sumwt=0, sumtt=0,pid;
 printf("\n***Waiting time***");
 printf("\nPID\tWtime");
 for(i=1; i<=n; i++)
  {
    printf("\n%d\t%d",proc[i].pid,wtime[i]);
    sumwt+=wtime[i];
  }
 printf("\nAverage:%.2f",(float)sumwt/n);
 printf("\n***Turnaround Time***");
 printf("\nPID\t ttime");
 for(i=1; i<=n; i++)
  {
     printf("\n%d\t%d",i,ttime[i]);
     sumtt+=ttime[i];
   }
 printf("\nAverage:%.2f",(float)sumtt/n);
 
}     





