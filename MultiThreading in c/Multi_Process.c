#include<sys/types.h>
#include<errno.h>

void start_timer();
float stop_timer();
int main(int argc,char **argv)
{
  int size = atoi(argv[1]);
  int *ptr;
  int n = size/sizeof(int);
  
  pid_t child_id,exit_id;
  int status;
  start_timer();
  child_id = fork();
  if(child_id >=0)
  {
   if(child_id ==0)
   {
    ptr = (int*)calloc(n,sizeof(int));
	if(ptr == NULL)
    exit(0);
    else{
    free(ptr);
    }
   }
  }
  exit_id = waitpid(-1,&status,0);
  if(exit_id == child_id)
  {
    stop_timer();
  }
 }
