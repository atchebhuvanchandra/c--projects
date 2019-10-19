#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void start_timer();
float stop_timer();

void* threadExample(void* v)
{
 int *_ptr = (int *)v;
 int size = *_ptr;
 int *ptr;
 int n = size/sizeof(int);
 ptr=(int*)calloc(n,sizeof(int));
if(ptr == NULL)
 exit(0);
 else{
 free(ptr);
 }
  return 0;
 }
 
 
 int main(int argc,char **argv)
 {
   int size = atoi(argv[1]);
   pthread_t pid;
   start_timer();
   pthread_create(&tid,NULL,&theadExample,&size);
   pthread_join(tid,NULL);
   stop_timer();
   exit(0);
 }
