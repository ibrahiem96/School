#include <stdio.h>
#include <stdlib.h>

/*Assignment: Project 2
  Name: Ibrahiem Mohammad
  net-ID: imoham3
  Due Date: 9/20/15
*/

typedef struct stack_struct
{
	char* darr;
	int size; //size of array
	int top; //specifies top of stack
} stack;

void stk_init(stack* st){

	st->size = 2;		//allocate space for 2 elements
	st->darr = (char*) malloc (sizeof(char) * st->size);
	st->top = -1;		//set top of stack value
}

int stk_check_if_empty(stack* st){

	if (st->top == -1){
		return 1;
	}
	
	return 0;

}

void stk_grow(stack* st){

	printf("\nDEBUG: in grow(): size: %d, top = %d", st->size, st->top);		
	char* temp = (char*) malloc (sizeof(char) * (st->size + 2));
	
	int i;
	for (i = 0; i < st->size; i++){
		temp[i] = st->darr[i];
	}

	free(st->darr);
	st->darr = temp;
	st->size = st->size + 2;

}

void stk_push(stack* st, char val){
	
	if (st->top+1 >= st->size){
		stk_grow(st);
	}
	st->darr[st->top+1] = val;
	st->top = st->top + 1;
}

void stk_pop(stack* st){

	if (stk_check_if_empty(st)==1){ 
		printf("\nStack is empty");
		abort();
	}
	
	st->darr[st->top] = st->darr[st->top--];
	st->top = st->top--;
	
}

char stk_get_top(stack* st){
	
	return (st->darr[st->top]);
}

void stk_print(stack* st){

	printf("\n--------TOP OF STACK--------");

	int i;
	for (i = st->top; i >= 0; i--){
		printf("\n%c", st->darr[i]);
	}
	
	printf("\n--------BOTTOM OF STACK--------"); 
}

void stk_reset(stack* st){

	free(st->darr);
	
	st->darr = NULL;
	st->size = 0;
	st->top = -1;
}




int main(int argc, char** argv){

	//get user input using fgets-each line is less than 300 characters, but array can be of infinite size (that's why we are growing the array)
	//if input contains only q/Q quit program

	stack st1; //instance of stack
	
	stk_init(&st1); //initialize stack
	
	printf("\nTop of stack value: %d", st1.top);

/*	stk_push(&st1, 'e');
       	printf("\ntop item val: %c", stk_get_top(&st1));	
     	printf("\ntop val: %d", st1.top);	
	stk_push(&st1, '$');
	printf("\ntop item val: %c", stk_get_top(&st1));	
       	printf("\ntop val: %d", st1.top);	
	stk_push(&st1, 'b');
	printf("\ntop item val: %c", stk_get_top(&st1));	
 	printf("\ntop val: %d", st1.top);	
	stk_pop(&st1);
	printf("\ntop item val: %c", stk_get_top(&st1));	
	printf("\ntop val: %d", st1.top);	
	
	stk_print(&st1);

*/

	//TODO:add debug info


	printf("\nEnter a series of symbols from the following list, less than 300 characters long: { [ ( < > ) ] }. In order to be balanced, each opening symbol must have a closing symbol (order matters). This program will tell you whether or not the symbols you entered are balanced.\nEnter q or Q to exit.\n");

	fgets(st1.darr, 300, stdin);
  	
	int i;	
	for (i = 0; i < sizeof(st1.darr); i++){
		if (st1.darr[i]=='q'||st1.darr[i]=='Q') exit(1);
  		char c = st1.darr[i];	
		if (c=='{'||c=='['||c=='('||c=='<'){
			stk_push(&st1, c);
		}
		if (c=='}'){
			if(stk_check_if_empty(&st1)==1){
				printf("\nString is unbalanced");
				printf("\n%s", st1.darr);
				return 0;
			}
			else if (st1.darr[st1->top]==c){
				stk_pop(st1);
				if (st1.darr[i+1]=='\0'){
					printf("\n%s", st1.darr);
				}
			}
			else {
				printf("\nString is unbalanced");
			}
			
		}
		if (c==']'){
			if(stk_check_if_empty(&st1)==1){
				printf("\nString is unbalanced");
				printf("\n%s", st1.darr);
				return 0;
			}
			else if (st1.darr[st1->top]==c){
				stk_pop(st1);
				if (st1.darr[i+1]=='\0'){
					printf("\n%s", st1.darr);
				}
			}
			else {
				printf("\nString is unbalanced");
			}
			
		}

		if (c==')'){
			if(stk_check_if_empty(&st1)==1){
				printf("\nString is unbalanced");
				printf("\n%s", st1.darr);
				return 0;
			}
			else if (st1.darr[st1->top]==c){
				stk_pop(st1);
				if (st1.darr[i+1]=='\0'){
					printf("\n%s", st1.darr);
				}
			}
			else {
				printf("\nString is unbalanced");
			}
			
		}

		if (c=='>'){
			if(stk_check_if_empty(&st1)==1){
				printf("\nString is unbalanced");
				printf("\n%s", st1.darr);
				return 0;
			}
			else if (st1.darr[st1->top]==c){
				stk_pop(st1);
				if (st1.darr[i+1]=='\0'){
					printf("\n%s", st1.darr);
				}
			}
			else {
				printf("\nString is unbalanced");
			}
			
		}	
	}

	stk_print(st1);

}
