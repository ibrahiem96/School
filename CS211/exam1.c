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
  
  llstack *temp = (struct llist_stack*)malloc(sizeof(struct llist_stack));


  if (isEmpty(temp)==1){
    exit(0);
  }

  temp->next = head;
  temp->top = val;
  if (Debug == 1){
    printf("Debugging Info: \n pushed value: %d", temp->top);
  head = temp;

}

void pop(STACK* head){

  llstack *temp = head;

  if (isEmpty(temp)==1){ 
    exit(0);
  }

  temp = temp->next;
  free(head);
  head = temp;

}

int top (llstack* head){

  return head->top;

}


 int main (int argc, char *argv[]){

  STACK* stack1 = (STACK*)malloc(sizeof(STACK));
  STACK* stack2 = (STACK*)malloc(sizeof(STACK));

  //insert and sort values
  printf ("Starting Expression Evaluation Program\n\n");
  printf ("Enter the values to be sorted and inserted in the stack:\n");

  int i = 0;
  int val;
  while (argv[i]>=0){
    scanf("%d", &val);
    
    while (isEmpty(stack1)==0 && top(stack1) < val){
        push(stack2, top(stack1));
        pop(stack1);
    }

    push(stack1, val);

    while (isEmpty(stack2)==0){
      push(stack1, top(stack2));
      pop(stack2);
    }

  }

  while (isEmpty(stack1)==0){
    printf("\n %d", top(stack1));
    pop(stack1);
  }


}


