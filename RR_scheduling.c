#include<stdio.h>
#include<stdlib.h>
struct proc_info
{
	int atime;
	int cpub;
	int pid; 
} proc[20], temp;

struct ganttchart
{
	int stime;
	int pid;
	int etime;
} gchart[20];

int i,j,ctime,n,gi=0,wtime[20],ttime[20],quantum, cnt;

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
	printf("\nHow many processes:");
	scanf("%d",&n);
	printf("\nPID\tATIME\tCPUB\n");
	for(i=1; i<=n; i++)
	{
		scanf("%d%d%d",&proc[i].pid, &proc[i].atime, &proc[i].cpub);
	}
	printf("\nEnter Time Quantum\t");
	scanf("%d",&quantum);
	for(i=1; i<=n; i++)
	{
		printf("\n%d\t%d\t%d",proc[i].pid, proc[i].atime, proc[i].cpub);
	}
}


void start()
{
	int pid;
	while(!finished())
	{	
		for(i=1; i<=n; i++)
		{
			cnt=0;
			if(proc[i].atime <= ctime && proc[i].cpub!=0)
			{
				wtime[i] = wtime[i]+(ctime-proc[i].atime);
				addgchart(proc[i].pid);
				while(cnt < quantum)
				{
					ctime++; 
					proc[i].cpub--;
					cnt++;
					if(proc[i].cpub==0)
					{
						printf("\nProc %d completed at time %d", proc[i].pid,ctime);
						ttime[i] = ctime-proc[i].atime;
					}
				}
			}
		}
	}
	gchart[gi].etime = ctime;
}

int finished()
{
	for(i=1; i<=n; i++)
	{
		if(proc[i].cpub != 0)
			return 0;
	}
	return 1;
}

void addgchart(int pid)
{
	gchart[++gi].pid = pid;
	gchart[gi].stime = ctime;
	gchart[gi-i].etime = gchart[gi].stime;
}


void dispgchart()
{
	printf("\n");
	for(i=1; i<=n; i++)
		printf("|--");
		printf("|\n");
	
	for(i=1; i<=n; i++)
		printf("| %d", gchart[i].pid);
		printf("|\n");

	for(i=1; i<=gi; i++)
		printf("|--");
		printf("|\n");

	for(i=1; i<=gi; i++)
		printf("%d  ",gchart[i].stime);

		printf("%d\t",gchart[gi].etime);
}

void disptimes()
{
	int sumwt=0, sumtt=0,pid;
	printf("\n\n**Waiting Time**");
	printf("\nPID\tWtimes");
	for(i=1; i<=n; i++)
	{
		printf("\n%d\t%d",proc[i].pid, wtime[i]);
		sumwt += wtime[i];
	}
	printf("\nAverage: %.2f", (float)sumwt/n);
	printf("\n\n**Turnaround Time**");
	printf("\nPID\tttime");
	for(i=1; i<=n;i++)
	{
		printf("\n%d\t%d",i,ttime[i]);
		sumtt+=ttime[i];
	}
	printf("\nAverage: %.2f", (float)sumtt/n);
	printf("\n");
}

			

