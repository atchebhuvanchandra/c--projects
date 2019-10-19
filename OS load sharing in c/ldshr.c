#include <stdio.h>
#include <ctype.h>
#include <rpc/rpc.h>
#include "ldshr.h"

int main(int argc,char argv)
{
  char mx[5] = "-max";
  char up[5] = "-upd";
  char *arg= argv[1];
  
  CLIENT         *cl[4];    /* a client handle */
  char           *value;
  int             key,i=0,loc=0;
  double l[4];
  abc value;
  char *ser[4]={"chopin","bach","degas","arthur"};
  if (!(cl[1] = clnt_create(ser[1], RDBPROG, RDBVERS, "tcp"))) {
    /*
     * CLIENT handle couldn't be created, server not there.
     */
    clnt_pcreateerror(ser[1]);
    exit(1);
  }

  if (!(cl[2] = clnt_create(ser[2], RDBPROG, RDBVERS, "tcp"))) {
    /*
     * CLIENT handle couldn't be created, server not there.
     */
    clnt_pcreateerror(ser[2]);
    exit(1);
  }

  if (!(cl[3] = clnt_create(ser[3], RDBPROG, RDBVERS, "tcp"))) {
    /*
     * CLIENT handle couldn't be created, server not there.
     */
    clnt_pcreateerror(ser[3]);
    exit(1);
  }

  if (!(cl[4] = clnt_create(ser[4], RDBPROG, RDBVERS, "tcp"))) {
    /*
     * CLIENT handle couldn't be created, server not there.
     */
    clnt_pcreateerror(ser[4]);
    exit(1);
  }
 if(strcmp(arg,mx)==0)
 {
  value.N = atoi(argv[2]);
  value.M = atoi(argv[3]);
  value.N = atoi(argv[4]);
  for(i=1;i<=4;++i){
  l[i] = getload_1(&value,cl[i]); 
  printf("%s : %lf",ser[i],l[i]);
  }
  printf("\n");
  double min = l[1];
  for(i=1;i<=4;++i){
  if(l[i] < min )
   {
   min = l[i];
   loc = i + 1;
   }
  }

  double ab = getmax_1(&abc,ser[loc]);
  printf("(executed on %s )\n %lf",ser[loc],ab);
 } 
}
