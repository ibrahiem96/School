/*  Assignment: Project 3 
 *  Author: Ibrahiem Mohammad
 *  Net-ID: imoham3
 *  Date: 10/3/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef enum {ERROR = 0, OPERATOR, VALUE, EOLN, QUIT, HELP} tokenType;

typedef struct tokenStruct
{
 tokenType type;
 char      op;
 int       val;
} token;

//value stack struct
typedef struct stack_struct
{
  int data;
  struct stack_struct *next_node;

} stack;

void init(stack* node){
  node = NULL;
}


void push(stack* node, int val)
{
  
  stack *p = (struct stack_struct*)malloc(sizeof(struct stack_struct));


  if (isEmpty(p)==1)
  {
    exit(0);
  }

  p->next_node = node;
  p->data = val;
  node = p;

}

void pop(stack* node)
{

  stack *p = node;

  if (isEmpty(p)==1)
  { 
    exit(0);
  }

  p = p->next_node;
  free(node);
  node = p;

}

int data (stack* node)
{

  return node->data;

}

int eval(int var1, char op, int var2)
{

  if (op=='+')
  {
    return var1+var2;
  }
  else if (op=='-')
  {
    return var2-var1;
  }
  else if (op=='*')
  {
    return var1*var2;
  }
  else if (op=='/')
  {
    return var2/var1;
  }

  else
  {
    printf("\nERROR");
    return -999;
  }
}


int isEmpty(stack* node)
{

  if (node == NULL)
  {
    return 1;
  }
  else 
  {
    return 0;
  }

}

token getInputToken (FILE *in);

void processExpression (token inputToken, FILE *in)
{
 /**********************************************/
 stack *val;
 stack *op;

 init(val);
 init(op);

 int popAndEval(stack *val, stack *op)
{

  if (isEmpty(val)==1)
  {
    printf("\nStack Empty");
    return -999;
  }

  char op = data(op);
  pop(op);

  int var2 = data(val);
  pop(val);

  int var1 = data(val);
  pop(val);

  int v3 = eval(var1, op, var2);
}

 /* Loop until the expression reaches its End */
 while (inputToken.type != EOLN)
   {
    /* The expression contains an OPERATOR */
    if (inputToken.type == OPERATOR){
       /* make this a debugMode statement */
       printf ("OP:%c, " ,inputToken.op);

      if (inputToken.op=='(')
      {
        push(op, inputToken.op);
      }
      if (inputToken.op=='+' || inputToken.op=='-')
      {
        while (isEmpty(op)==0 && (op->data=='+' || op->data=='-' || op->data=='*' || op->data=='/'))
        {
          popAndEval(op, val);
        }
        push(op, inputToken.op);
      }
      if (inputToken.op=='*' || inputToken.op=='/')
      {
        while (isEmpty(op)==0 && (op->data=='*' || op->data=='/'))
        {
          popAndEval(op, val);
        }
        push(op, inputToken.op);
      }
      if (inputToken.op==')')
      {
        while (isEmpty(op)==0 && op->data!='(')
        {
          popAndEval(op, val);
        }
        if (isEmpty(op)==1)
        {
          printf("\nOperator stack empty");
        }
        else
        {
          pop(op);
        }
      }
    }

    /* The expression contain a VALUE */
    else if (inputToken.type == VALUE)
      {
       /* make this a debugMode statement */
       printf ("Val: %d, ", inputToken.val); 

       push(val, inputToken.val);
        
      }
   
    /* get next_node token from input */
    inputToken = getInputToken (in);
   } 

 /* The expression has reached its end */

 while (isEmpty(op)==0)
 {
  popAndEval(op, val);
 }

 printf ("\n");
}


/**************************************************************/
/*                                                            */
/*  The Code below this point should NOT need to be modified  */
/*  for this program.   If you feel you must modify the code  */
/*  below this point, you are probably trying to solve a      */
/*  more difficult problem that you are being asked to solve  */
/*                                                            */
/**************************************************************/

token getInputToken (FILE *in)
{
 token retToken;
 retToken.type = QUIT;

 int ch;
 ch = getc(in);
 if (ch == EOF)
   return retToken;
 while (('\n' != ch) && isspace (ch))
   {
    ch = getc(in);
    if (ch == EOF)
      return retToken;
   }
 
 /* check for a q for quit */
 if ('q' == ch)
   {
    retToken.type = QUIT;
    return retToken;
   }

 /* check for a ? for quit */
 if ('?' == ch)
   {
    retToken.type = HELP;
    return retToken;
   }

 /* check for the newline */
 if ('\n' == ch)
   {
    retToken.type = EOLN;
    return retToken;
   }

 /* check for an operator: + - * / ( ) */
 if ( ('+' == ch) || ('-' == ch) || ('*' == ch) ||
      ('/' == ch) || ('(' == ch) || (')' == ch) )
   {
    retToken.type = OPERATOR;
    retToken.op = ch;
    return retToken;
   }
   
 /* check for a number */
 if (isdigit(ch))
   {
    int value = ch - '0';
    ch = getc(in);
    while (isdigit(ch))
      {
       value = value * 10 + ch - '0';
       ch = getc(in);
      }
    ungetc (ch, in);  /* put the last read character back in input stream */
    retToken.type = VALUE;
    retToken.val = value;
    return retToken;
   }
      
 /* else token is invalid */
 retToken.type = ERROR;
 return retToken;
}

/* Clear input until next_node End of Line Character - \n */
void clearToEoln(FILE *in)
{
 int ch;
 
 do {
     ch = getc(in);
    }
 while ((ch != '\n') && (ch != EOF));
}

void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}

int main (int argc, char **argv)
{

 char *input;
 token inputToken;

 printf ("Starting Expression Evaluation Program\n\n");
 printf ("Enter Expression: ");

 inputToken = getInputToken (stdin);
 while (inputToken.type != QUIT)
   {
    /* check first Token on Line of input */
    if(inputToken.type == HELP)
      {
       printCommands();
       clearToEoln(stdin);
      }
    else if(inputToken.type == ERROR)
      {
       printf ("Invalid Input - For a list of valid commands, type ?\n");
       clearToEoln(stdin);
      }
    else if(inputToken.type == EOLN)
      {
       printf ("Blank Line - Do Nothing\n");
       /* blank line - do nothing */
      }
    else 
      {
       processExpression(inputToken, stdin);
      } 

    printf ("\nEnter Expression: ");
    inputToken = getInputToken (stdin);
   }

 printf ("Quitting Program\n");
 return 1;
}
