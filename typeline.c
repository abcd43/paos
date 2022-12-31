
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

char comm[100],*ptr;
char *args[10];
int tot;

void typeline(char *option,char *fname);
void getcomm();
void sep_arg();
void take_action();

void main()
{
	do
	{
		printf("\nMyShell$");
		getcomm();
		sep_arg();
		take_action();
	}while(1);
}

void sep_arg()
{
	int i, j;
	char *token;
	i = j = tot =0;
	
	token = strtok(comm," ");
	while(token != NULL)
	{
		args[tot] = (char*)malloc(20);
		strcpy(args[tot++],token);
			token = strtok(NULL, " ");
	}
	for(i=0; i<tot; i++)
	{
		printf("%s",args[i]);
	}
	return;
}
void getcomm()
{
	int len;
	ptr = fgets(comm, 80,stdin);
	len = strlen(comm);
	comm[len-1] = '\0';
	return;
}

void take_action()
{
	char  str[100];
	pid_t  pid;
	int status;
	

	if( strlen(comm) <= 1)
		return;
		if(strcmp(args[0],"typeline") == 0)
			typeline(args[1],args[2]);
			else
				
				pid = fork();
				if(pid==0)
				
				{
					execvp(args[0],args);
					strcpy(str,"./");
					strcat(str,args[0]);
					execvp(str,args);
					printf("\n%s: Command not found", comm);
					exit(0);
				}
				else
					waitpid(pid,&status,0);
}

void typeline(char *option, char *fname)
{
	FILE *fp;
	char str[80];	
	int tot_lines,ch,n,cnt;
	//count the lines file
	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("\nUnable to Open file");
		return;
	}
	tot_lines = 0;
	while(!feof(fp))
	{
		fgets(str,80,fp);
		tot_lines++;
	}
	fclose(fp);
	if(strcmp(option, "a")==0)
	{
			fp=fopen(fname,"r");
			while(!feof(fp))
			{
				fgets(str,80,fp);
				if(feof(fp))
					break;
				printf("%s",str);
			}
		fclose(fp);
	}
	else
		if(option[0]== '+')
		{
			n = atol(option+1);
			if(n > tot_lines)
			{
				printf("\ninvalid number of lines");
				return;
			}
			fp=fopen(fname,"r");
			cnt = 0;
			while(cnt < n)
			{
				fgets(str,80,fp); if(feof(fp)) break;
				printf("%s",str);
				cnt++;
			}
			fclose(fp);
		}
		else
		if(option[0]== '-')
		{
			n = atoi(option+1);
			if(n > tot_lines)
			{
					printf("\ninvalid number of lines");
					return;
			}
			fp = fopen(fname,"r");
			cnt = 0;
			while(cnt < tot_lines - n)
			{
				fgets(str,80,fp); if(feof(fp)) break;
				cnt++;
			}
			while(!feof(fp))
			{
				fgets(str,80,fp); if(feof(fp)) break;
				printf("%s",str);
				cnt++;
			}
		fclose(fp);
		}		
		else	
			printf("\nInvalid options");	
}
          
                   
                          




