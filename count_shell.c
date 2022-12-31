//Seat NO:
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<wait.h>
char command[100], *ptr;
char *args[10];

int total;

	void count(char *option, char *fname);

	void getcomm()
	{
		int len;
		ptr = fgets(command,80,stdin);
		len = strlen(command);
		command[len-1] = '\0';
		return;
	}

	void take_action()
	{
		char str[100];
		pid_t pid;
		int status;
		
		ptr = command;
		if(ptr == NULL)
			exit(0);
		if (strlen(command) <= 1)
			return;
			if(strcmp(args[0],"count") == 0)
			{
			  count(args[1],args[2]);
			}
			else if(pid = fork() < 0 )
			{
				printf("\nUnable to create process");
			}
			else if(pid == 0)
			{
				execvp(args[0],args);
				strcpy(str,",/");	
				strcat(str,args[0]);
				execvp(str,args);
				printf("\n %s : command not FOUND ", command);
				exit(0);
			}
			else	
				waitpid(pid,&status,0);
		}	

		void count(char *option, char *fname)	
		{
			int ccnt, wcnt, lcnt, wflag;
			int ch;
			FILE *fp;
			int i;
			fp = fopen(fname, "r");
			if(fp == NULL)
			{
				printf("\nUnable To Open File");
				exit(0);
			}
				ccnt = wcnt = lcnt = 0;
				ch = fgetc(fp);	
				while(ch != EOF)
				{
					ccnt ++;
					if(ch == ' ' || ch == '\t')
					{
                                           wcnt++;
                                         }						
					else if(ch=='\n')
                                         {
                                                wcnt++;
                                                 lcnt++;
                                         }
						ch = fgetc(fp);		
					
				}
					fclose(fp);
				if(strcmp(option,"c") == 0 )
				{
					printf("\nTotal characters = %d\n",ccnt);
					}
				else if(strcmp(option,"w") == 0)
					{
						printf("\nTotal words = %d\n",wcnt);
						}
				else if(strcmp(option , "l") == 0)
				{
					printf("\nTotal Lines = %d\n",lcnt);
					}
				else 
				{
					printf("\nInvalid Option");
					}
		}
					
	void sep_arg()
	{
		int i, j;
		char *token;
		i = j = total = 0;

		token = strtok(command," ");
	
		while(token != NULL)
		{
		args[total] = (char*)malloc(20);
		strcpy(args[total++], token);
			token = strtok(NULL," ");
			}
		return;
		}
	
int main()
{
	do
	{
		printf("\nMyShell$");
		getcomm();
		sep_arg();
		take_action();
	} while(1);
} 

