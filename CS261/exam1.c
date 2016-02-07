/*  Assignment: Exam 1 
 *  Author: Ibrahiem Mohammad
 *  Net-ID: imoham3
 *  Date: 10/21/2015
 *  STACK-SORT PROGRAM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
  int top;
  struct stack *next;

} STACK;

int isEmpty(STACK* head){

  if (head == NULL){
    return 1;
  }
  else {
    return 0;
  }

}

void push(STACK* head, int val){
  
  STACK *temp;

  printf("sanity check - push");
  
  if (head == NULL){
    printf("\nBENCHMARK 1 - PUSH");
    head = (STACK*)malloc(1*sizeof(STACK));  
    head->next = NULL;
    head->top = val;
  }

  else{
     printf("\nBENCHMARK 2 - PUSH");
    temp = (STACK*)malloc(sizeof(STACK));
    temp->next = head;
    temp->top = val;
    head = temp;
  }

}

void pop(STACK* head){

  STACK *temp = head;

  if (isEmpty(temp)==1){ 
    exit(0);
  }

  temp = temp->next;
  free(head);
  head = temp;

}

int top (STACK* head){

  return head->top;

}


 int main (){

  STACK* stack1;
  STACK* stack2;
  STACK *temp;

  //insert and sort values
  printf ("Starting Expression Evaluation Program\n\n");
  printf ("Enter the values to be sorted and inserted in the stack:\n");
  int val;
  scanf("%d", &val);
  while (val > -1){
	stack1 = (STACK*)malloc(sizeof(STACK));
        stack1->top = val;
	stack1->next = stack1;
	temp = stack1;
	scanf("%d", &val);
  }


  stack1 = temp;

  //stack 1 must be sorted first

  int x;	
  while (stack1->next!=NULL){
    x = stack1->top;

    while (isEmpty(stack1)==0 && (top(stack1) < x)){
  	printf("inside loop");	 
        push(stack2, top(stack1));
        pop(stack1);
        stack1 = stack1->next;
    }
    
    push(stack1, x);

    while (isEmpty(stack2)==0){
      push(stack1, top(stack2));
      pop(stack2);
    }
   stack1 = stack1->next;
  }
printf("\nWORKS3"); 
  while (isEmpty(stack1)==0){
    printf("\n %8d", top(stack1));
    pop(stack1);
  }
}


