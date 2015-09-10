#include <stdio.h>
#include <stdlib.h>
#include <time.h>




// pre-written function to print elements of an array.
//   might be handy as a sanity check.
void p_array(int a[], int n) {
int i;

  printf("----\n");
  for(i=0; i<n; i++) {
    printf("%i\n", a[i]);
  }
  printf("----\n");
}

// Stub of a function to populate the elements of an array
//   with pseudo-random integers.
void pop_array(int a[], int n) {

  // your code here
}

// this might be handy!
int log_2(int n) {
  if(n==1) return 0;
  return 1 + log_2(n/2);
}

int cmp_int(const void *a, const void *b) {

  // YOUR CODE HERE
}

int  main(int argc, char **argv) {
int n;

  srand(time(NULL));
  if(argc > 1)
    n = atoi(argv[1]);
  else
    n = 16;

  int data[n];

  // WRITE YOUR CODE HERE TO CONDUCT THE EXPERIMENT

}
