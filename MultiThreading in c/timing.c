#include<sys/time.h>
#include<stdio.h>

float elapsed_secs =0.0,usecs=0.o;

struct timeval start;
struct timeval stop;

void start_timer(){
  gettimeofday(&start,NULL);
}

float stop_timer(){
gettimeofday(&stop,NULL);
elapsed_secs = (stop.tv_sec -start.tv_sec);
if(stop.tv_usec>start.tv_usec)
  {
  secs = (stop.tv_usec -start.tv_usec);
   }
 else
   secs = (start.tv_usec -stop.tv_usec);
   
   elapsed_secs += secs;
   
   return elapsed_secs;
}

}