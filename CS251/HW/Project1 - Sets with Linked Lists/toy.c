
#include "sset.h"
/*This is a test file for sset.c*/
int main(){
SSET *s;
SSET *s2;

  int a[] = {2, 8, 1, 3, 1, 8, 0, 4};
  int b[] = {1, 7, 4, 8, 3, 2};
//  s = sset_from_array(a, 8);
//  s2 = sset_from_array(b, 6);
  SSET* p;
  p = sset_diff(s, s2);
  sset_display(p);
}

  
