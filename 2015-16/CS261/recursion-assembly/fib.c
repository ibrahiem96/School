#include <stdio.h>
int fib(int n)
{
if (n<=1)
return 1;

return(fib(n-1)+fib(n-2));

}

int main() {
int n =5;
printf("Fib of %d is %d\n",n,fib(n));
}
