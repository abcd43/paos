#include<stdio.h>
#include<stdlib.h>

struct proc_info
{
		int atime;
		int cpub;
		int pid;
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
		printf("\n PID\tATIME \tCPUB \n");
		for(i=1;i<=n; i++)
		{
				scanf("%d%d%d",&proc[i].pid,&proc[i].atime,&proc[i].cpub);
		}
		for(i=1;i<=n;i++)
		{
				for(j=i+1;j<=n;j++)
				{
						if(proc[i].atime>proc[j].atime)
						{
								temp=proc[i];
								proc[i]=proc[j];
								proc[j]=temp;
						}
				}
		}
		for(i=1;i<=n;i++)
		{
				printf("\n %d\t%d\t%d",proc[i].pid,proc[i].atime,proc[i].cpub);
		}
}

void start()
{
		int pid;
		for(i=1;i<=n;i++)
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

void dispgchart()
{
		printf("\n");
		for(i=1;i<=gi; i++)
		printf("|--");
		printf("|\n");
		
		for(i=1;i<=gi;i++)
		{
				printf("| %d",gchart[i].pid);
				printf("|\n");
				
				for(i=1;i<=gi;i++)
				printf("|--");
				printf("|\n");
				
				for(i=1;i<=gi;i++)
				printf("%d		",gchart[i].stime);
				printf("%d\n",gchart[gi].etime);
		}
}
		
		void disptimes()
		{
				int sumwt=0,sumtt=0,pid;
				printf("\n**Waiting Times**");
				printf("\nPID\t Wtime");
				for(i=1;i<=n;i++)
				{
						printf("\n%d\t%d",proc[i].pid,wtime[i]);
						sumwt+=wtime[i];
				}
				printf("\n Average:%2f",(float)sumwt/n);
				
				printf("\n**Turnaround Time**");
				printf("\nPID\t ttime");
				for(i=1;i<=n;i++)
				{
						printf("\n%d\t %d",i,ttime[i]);
						sumtt+=ttime[i];
				}
				printf("\nAverage:%.2f",(float)sumtt/n);
		}
