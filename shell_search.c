#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

char comm[100],*ptr;
char *args[10];
int tot_arg;

void getcomm();
void sep_arg();
void take_action();
int search(char option,char *pattern,char *fname);
 void main()
{
	do
	{
		printf("\nMyshell $");
		getcomm();
		sep_arg();
		take_action();
	}while(1);
}

void sep_arg()
{
	int i, j;
	char *token;
	i = j = tot_arg =0;
	
	token = strtok(comm," ");
	while(token != NULL)
	{
		args[tot_arg] = (char*)malloc(20);
		strcpy(args[tot_arg++],token);
			token = strtok(NULL, " ");
	}
	for(i=0; i<tot_arg; i++)
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
		if(strcmp(args[0],"search") == 0)
			search(*args[1],args[2],args[3]);
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

int search(char option,char *pattern,char *fname)
{
	char buff[100],*ptr;
	int cnt;
	FILE *fp;
	int i;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\nUnable to open file");
		exit(0);
	}
	switch(option)
	{
		case 'a':while(!feof(fp))
			{
				buff[0]='\0';
				fgets(buff,80,fp);
				ptr=strstr(buff,pattern);
				if(ptr !=NULL)
					printf("%s",buff);
			}
				fclose(fp);
				break;
		case 'c':cnt=0;
			while(!feof(fp))
			{
				buff[0]='\0';
				fgets(buff,80,fp);
				ptr=strstr(buff,pattern);
				while(ptr!=NULL)
				{
				cnt++;
				ptr=ptr+strlen(pattern);
				ptr=strstr(ptr,pattern);
				}
			}
			fclose(fp);
			printf("\n Ther search string %s occours %d times",pattern ,cnt);
			break;
		case 'f':while(!feof(fp))
			{
				buff[0]='\0';
				fgets(buff,80,fp);
				ptr=strstr(buff,pattern);
				if(ptr!=NULL)
				{
					printf("%s",buff);
					break;
				}
			}
				fclose(fp);
				break;
		}
		return(0);
	}	
                          




