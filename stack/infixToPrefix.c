#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.h" // Make sure to include your stack implementation

int space(char symbol);
int isOperand(char symbol);
int isOperator(char symbol);
int checkIfOperand (char ch);
int precedence(char ch);
int getPostfix(char* expression);
void reverse(char* exp);
void brackets(char* exp);
void InfixtoPrefix(char* exp);


int main (){
	
	char expression[] = "((a/b)+c)-(d+(e*f))";
	
	printf ("The infix is: ");
	printf ("%s\n", expression);
	InfixtoPrefix (expression);
	
	printf ("The prefix is: ");
	printf ("%s\n", expression);
	
	return 0;
}



int space(char symbol) {
    return (symbol == ' ' || symbol == '\t');
}

int isOperand(char symbol) {
    return (isdigit(symbol) || (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'));
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '%');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
        case '%':
            return 2;

        case '^':
            return 3;

        default:
            return 0;
    }
}

// The driver function for infix to postfix conversion 
int getPostfix (char* expression){
	
	int i, j;
	
	// Stack size should be equal to expression size for safety  
	stack s;
	init(&s);
	  
	for (i = 0, j = -1; expression[i]; ++i){
		if(isOperand(expression[i])){
			expression[++j] = expression[i];
		}else if (expression[i] == '('){
			push (&s, expression[i]);
		}else if(expression[i] == ')'){
		  while (!is_empty(&s) && top(&s) != '(')
		    expression[++j] = pop(&s);
		  if(!is_empty(&s) && top(&s) != '('){
		  	return -1;		// invalid expression              
		  }
		  else{
		  	pop(&s);
		  }
		}else{			// if an opertor
		  while (!is_empty(&s) && precedence (expression[i]) <= precedence (top(&s))){
		  	expression[++j] = pop(&s);
		  }
		  push (&s, expression[i]);
		}
	
	    }
	
	  // Once all inital expression characters are traversed
	  // adding all left elements from stack to exp
	  while (!is_empty(&s))
	    expression[++j] = pop(&s);
	
	  expression[++j] = '\0';
}

void reverse(char* exp){
	
	int size = strlen(exp);
	int j = size, i = 0;
	char temp[size];
	
	temp[j--] = '\0';
	while (exp[i] != '\0'){
	    temp[j] = exp[i];
	    j--;
	    i++;
	}
	strcpy (exp, temp);
}

void brackets(char* exp){
	
	int i = 0;
	while (exp[i] != '\0'){
      if (exp[i] == '('){
      	 exp[i] = ')';
	  }else if(exp[i] == ')'){
	  	exp[i] = '(';
	  }
      i++;
    }
}

void InfixtoPrefix(char* exp){

  int size = strlen (exp);

  // reverse string
  reverse (exp);
  //change brackets
  brackets (exp);
  //get postfix
  getPostfix (exp);
  // reverse string again
  reverse(exp);
}
