
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <dirent.h>

char comm[100],*ptr;
char *args[10];
int tot;

 
void list(char *option, char *dirname);
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

	ptr = comm;
	if(ptr == NULL)
		exit(0);
	if( strlen(comm) <= 1)
		return;
		if(strcmp(args[0],"list") == 0)
			list(args[1],args[2]);
			else
				if((pid = fork() < 0))
				{
					printf("\n Unable to create process");
				}
			else
				if(pid == 0)
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

void list(char *option, char *dirname)
{
	DIR *dp;
	struct dirent *dent;
	int cnt;
	if(strcmp(option, "-f")==0)
	{
			dp = opendir(dirname);
			if(dp == NULL)
			{
				printf("\nUnable to open directory\n");
				exit(0);
			}
			dent = readdir(dp);
			while(dent != NULL)
			{
				printf("\n%s", dent->d_name);
				dent = readdir(dp);
			}
			printf("\n");
	}
	else
		if(strcmp(option, "-n")==0)
		{
			cnt = 0;
			dp = opendir(dirname);
			if(dp == NULL)
			{
				printf("\nUnable to open dir");
				exit(0);
			}
			dent = readdir(dp);
			while(dent != NULL)
			{
				cnt++;
				dent = readdir(dp);
			}
			printf("\nTotal dir entries :\t %d\n",cnt);
			closedir(dp);
		}
		else
		if(strcmp(option, "-i")==0)
		{
			
			dp = opendir(dirname);
			if(dp == NULL)
			{
				printf("\nUnable to open dir");
				exit(0);
			}
			dent = readdir(dp);
			while(dent != NULL)
			{
				printf("\n%s %ld",dent->d_name,dent->d_ino);
				dent = readdir(dp);
			}
			printf("\n");
			closedir(dp);
		}
		else
				printf("\n>>Invalid Option<<\n");
}

