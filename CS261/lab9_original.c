#include<sys/time.h>
#include<stdio.h>

struct timeval tvalBefore, tvalAfter;
#define  DIM 100


    



void matrixvector(int first[][DIM], int second[][1], int result[][1])
{
int c;
int d;
int k;

for ( c = 0 ; c < DIM ; c++ )
    {
      for ( d = 0 ; d < 1 ; d++ )
      {
        for ( k = 0 ; k < DIM ; k++ )
        {
          result[c][d] += first[c][k]*second[k][d];
        }
      }
    }

}
int main() {

gettimeofday(&valBefore, NULL);	
	
int first[DIM][DIM];
int second[DIM][1];
int result[DIM][1];
int i=0;
int j=0;	
 for (i=0;i<DIM;i++) 
    for (j=0;j<DIM;j++)
	 {
	 	first[i][j]=i+j;
	 	second[i][0]=(i+1)*(j+1);
	 	result[i][0]=0;
	 }


    matrixvector(first,second,result);
 
 for (i=0;i<DIM;i++) 
 printf("%d ",result[i][0]);

 
 gettimeofday(&tvalAfter, NULL);
 printf("\nElapsed time: %ums\n", (unsigned int)(tvalAfter.tv_usec-tvalBefore.tv_usec));
    
}

