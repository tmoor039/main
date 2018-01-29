/* Need to review. Costum code integrated wit D`r. Raju Rangaswami's original 4338
 demo and modified to fit into our lecture. */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_ARGS 20
#define BUFSIZ 1024

int get_args(char* cmdline, char* args[])
{
    int i = 0;
    
    /* if no args */
    if((args[0] = strtok(cmdline, "\n\t ")) == NULL)
        return 0;
    
    while((args[++i] = strtok(NULL, "\n\t ")) != NULL) {
        if(i >= MAX_ARGS) {
            printf("Too many arguments!\n");
            exit(1);
        }
    }
    /* the last one is always NULL */
    return i;
}

void execute(char* cmdline)
{
    int pid,pid2, async, i ;
    char* args[MAX_ARGS];
    char* args2[3];
    char *command = NULL ;
    char * fileName = NULL;
    int filedes[2];
    
    
    int nargs = get_args(cmdline, args);
    if(nargs <= 0) return;
    
    
    if (pipe(filedes) == -1)
    {
        perror("pipe file descriptor erroes ");
        exit(1);
    }
    
    if(!strcmp(args[0], "quit") || !strcmp(args[0], "exit")) {
        exit(0);
    }
    
    /* check if async call */
    if(!strcmp(args[nargs-1], "&")) { async = 1; args[--nargs] = 0; }
    else async = 0;
    
    // allocate memory for command
    
    for ( i = 0; i < nargs; i++)
    {
        if (strcmp(args[i], ">")==0)
        {
            command = malloc(strlen(args[0])*sizeof(char));
            strcpy(command, args[i]); // must malloc for command
            fileName = malloc(15*sizeof(char));
            strcpy(fileName,args[nargs-1]); // xget fileName name
            
            break;
        }
        else if(strcmp(args[i],"<")==0)
        {
            command = malloc(strlen(args[0])*sizeof(char));
            strcpy(command, args[i]);
            fileName = malloc(15*sizeof(char));
            strcpy(fileName,args[nargs-1]); // get fileName name
            break;
        }
        else if ((strcmp(args[i],"|")==0))
        {
            command = malloc(strlen(args[0])*sizeof(char));
            strcpy(command, args[i]);
            fileName = malloc(15*sizeof(char));
            strcpy(fileName,args[nargs-1]); // get fileName name
            break;
        }
        else
        {
            command = NULL;
        }
        
    }
    
    // if statements contingient on the cases entered by the user
    if(command == NULL)
    {
        pid = fork();
        if(pid == 0) { /* child process */
            execvp(args[0], args);
            /* return only when exec fails */
            perror("exec failed");
            exit(-1);
        } else if(pid > 0) { /* parent process */
            if(!async) waitpid(pid, NULL, 0);
            else printf("this is an async call\n");
        } else { /* error occurred */
            perror("fork failed");
            exit(1);
        }
        
    }
    
    // redirect standard output to file
    else if(strcmp(command,">")== 0)
    {
        
        filedes[1] = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        args[nargs-2] = (char *)0;
        
        pid = fork();
        if(pid == 0)
        {
            dup2(filedes[1],STDOUT_FILENO);
            close(filedes[1]);
            execvp(args[0], args);// execute the arguments
            /* return only when exec fails */
            perror("exec failed!!");
            exit(-1);
        }
        else if (pid > 0)
        {
            if(!async) waitpid(pid, NULL, 0);
            
            else printf("this is an async call\n");
        }
        else
        {
            perror("fork failed");
            exit(1);
        }
        
        
        
        
    }
    
    // redirect standard input to file
    else if (strcmp(command,"<")== 0)
    {
        
        if ((filedes[0] = open(fileName, O_RDONLY))== -1)
        {
            perror("FILE ERROR");
        }
        // this makes the exec function stop before the > or < or |
        args[nargs-2] = (char *)0; // for reading command
        
        
        pid = fork();
        
        if (pid == 0)
        {
            close(0); // close stdin
            dup(filedes[0]);// make the dile descriptor filedes[0]
            // close file descriptor
            close(filedes[0]);
            execvp(args[0], args);
        }
        else if(pid > 0) { /* parent process */
            if(!async) waitpid(pid, NULL, 0);
            else printf("this is an async call\n");
        } else { /* error occurred */
            perror("fork failed");
            exit(1);
        }
        
    }
    
    else if(strcmp(command,"|")== 0)
    {
        
        pid = fork();
        
        args[nargs-3] = (char *)0;
        args2[0] = args[nargs-2];
        args2[1] = args[nargs-1];
        args2[2] =(char *)0;
        
        if(pid == 0)
        {
            close(0);
            dup(filedes[0]);
            close(filedes[1]);
            execlp(args[nargs-2], args[nargs-2],args[nargs-1],NULL);
            //  execvp(args[0], args);// execute the arguments
            /* return only when exec fails */
            perror("exec failed!!");
            exit(-1);
        }
        else
        {
            
            
            
        }
        
        pid2 = fork();
        if (pid2 == 0)
        {
            close(1);
            dup(filedes[1]);
            close(filedes[0]);
            execvp(args[0], args);// execute the arguments
            //  execvp(args2[0], args2);
            /* return only when exec fails */
            perror("exec failed!!");
            exit(-1);
        }
        
        else if (pid > 0)
        {
            waitpid(pid2,NULL,0);
            
            if(async)
            {
                printf("this is an async call\n");
            }
        }
        
        else
        {
            perror("fork failed");
            exit(1);
        }
    }
}


int main (int argc, char* argv [])
{
    char cmdline[BUFSIZ];
    
    for(;;) {
        printf("COP4338$ ");
        if(fgets(cmdline, BUFSIZ, stdin) == NULL) {
            perror("fgets failed");
            exit(1);
        }
        execute(cmdline) ;
        
    }
    return 0;
}
