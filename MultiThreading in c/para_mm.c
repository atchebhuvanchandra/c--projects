#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

//defining and creating the matrix
#define max 240

int mat1[max][max];
int mat2[max][max];
int result[max][max];
int step_i=0;

//timer functions implicit declaration
void start_timer();
float stop_timer();

//using pthread_barrier
static pthread_barrier_t mybarrier;

//splitting the matrix multiplication into threads and the number of threads is taken by the user

void* multi_thread(void* t)
{
	int *n_t = (int*)t;
	int n_threads = *n_t;
	int first_row = step_i++;
	int i,j,k;
	for(i = first_row * max/n_threads;i<(first_row+1)*max/n_threads;i++)
	  for(j=0;j<max;j++)
            for(k=0;k<max;k++)
	      result[i][j] += (mat1[i][k] * mat2[k][j]);
	pthread_barrier_wait(&mybarrier);
return NULL;
}

int main(int argc,char **argv)
{
  int n_threads = atoi(argv[1]);
  int a=0,r=0,c=0;
  float time;
  pthread_t threads[n_threads];
  for(r=0;r<max;r++)
  {
   for(c=0;c<max;c++){
   mat1[r][c] = 1;
   mat2[r][c] = 2;
   }
  }
 start_timer();
  pthread_barrier_init(&mybarrier,NULL,n_threads+1);
  for(a=0;a<n_threads;a++){
    pthread_create(&threads[a],NULL,multi_thread,&n_threads);
  }

  pthread_barrier_wait(&mybarrier);
  for(a=0;a<n_threads;a++)
  {
    pthread_join(threads[a],NULL);
  }
   // pthread_barrier_wait(&mybarrier);
 time = stop_timer();
  for(r=0;r<max;r++){
     for(c=0;c<max;c++)
     {
	     printf(" %d ",result[r][c]);   
  } 
     printf("\n");
}
 printf("\n elapsed time = %f \n",time);
  return 0;

}
