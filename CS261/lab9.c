

#include<sys/time.h>
#include<stdio.h>

struct timeval tvalBefore, tvalAfter;

#define  DIM 100


void matrixvector(int first[][DIM], int second[][1], int result[][1])
{
int c;
int k;

for ( c = 0 ; c < DIM ; c++ )
    {
      for ( k = 0 ; k < DIM ; k++ )
      {
        result[c][0] += first[c][k]*second[k][0];
      }
    }

}
int main() {

gettimeofday(&tvalBefore, NULL);	
int first[DIM][DIM];
int second[DIM][1];
int result[DIM][1];
int i; 
 for (i=0;i<DIM;i++){ 
	 	
	first[i][i]=i+i;
	second[i][0]=(i+1)*1;
	result[i][0]=0;

	second[i][1]=(i+1)*2;
 	result[i][1]=0;

 }

 
 matrixvector(first,second,result);

 for (i=0;i<DIM;i++){ 
 printf("%d ",result[i][0]);
 }

 gettimeofday(&tvalAfter, NULL);
 printf("\nElapsed time: %ums\n", (unsigned int)(tvalAfter.tv_usec-tvalBefore.tv_usec));
}
