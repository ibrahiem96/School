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

	if (st->top == -1) return 1;
	else return 0;

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
	
	if (st->top+1 >= st->size)
		stk_grow(st);
	st->top = st->top+1;	
	st->darr[st->top] = val;
}

void stk_pop(stack* st){

	if (stk_check_if_empty(&st)==1)
		printf("\nStack is empty");
		exit(1);
	
	int i;
	i = st->darr[st->top];
	st->top = st->top-1;
	
}

char stk_get_top(stack* st){
	
	return (st->darr[st->top]);
}

void stk_reset(stack* st){

	free(st->darr);
	
	st->darr = NULL;
	st->size = 0;
	st->top = -1;
}



int main(){

	//get user input using fgets-each line is less than 300 characters, but array can be of infinite size (that's why we are growing the array)
	//if input contains only q/Q quit program

	stack st1; //instance of stack
	
	stk_init(&st1); //initialize stack
	
	printf("\nTop of stack value: %d", st1.top);

	stk_push(&st1, 'e');
        stk_push(&st1, '$');

        stk_push(&st1, 'b');
	
	
	printf("\ntop value: %d", st1.top);
	printf("\ntop item val: %c", stk_get_top(&st1));	
	stk_pop(&st1);
	printf("\nworks till here");
        stk_push(&st1, '^');
	printf("\nworks till here");
	

}
