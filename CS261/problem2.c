#include<stdio.h>

//returns 1 if x can be represented as an n-bit, 2's complement; 0 otherwise
int prob2(long int x, long int n){
	//calc num of high order bits left
 	int i = 65 + ~n;
	//zero out high order bits
	int shiftr = ((x << i) >> i);
	//return shiftr == x
	return !(shiftr ^ x);
}

int main(){

	printf("\n%d",prob2(5, 3));
	printf("\n%d", prob2(-4,3));
}
