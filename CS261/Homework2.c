#include<stdio.h>

/*Assignment: Homework 2
 *Date Due: 9/11/15
 *Name: Ibrahiem Mohammad
 *Net-ID: imoham3
*/

 /*1) It took 13 assembly instructions for my progrm to complete
   2) The index variable is located at 0x000000000040053e in rbp. It is later accessed at 0x0000000000400556.
   3) The string is stored at 0x000000000040054c in eax
   4) After iterating 17 times I found the following by printing the values in each register:
   "x $rbp": 0x00400570
   "x $rsp": 0xffffdf70
   "x printf": 0xd8ec8148
   the other registers are shown in the image in the zip file along with the assembly code
   */

int main(){
	int i;
	for (i = 0; i <= 25; i++){
		printf("\nSeptember is hot in Chicago this year");
	}
}
