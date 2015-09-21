
#include "sset.h"
/*This is a test file for sset.c*/
int main(){
SSET *s;

  int a[] = {2, 8, 1, 3, 1, 8, 0, 4};

  s = sset_from_array(a, 8);

  sset_free(s);
  sset_display(s);

}

  
