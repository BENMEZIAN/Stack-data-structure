#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.h"


int space(char symbol);
int isOperand(char symbol);
int isOperator(char symbol);
int precedence(char ch);
void infixToPostfix(char* infix, char* postfix);


int main(){
	
    char* infix = "(23 + 14) - (8 % 4)";
	char postfix[] = ""; // Initialize an empty postfix string

    infixToPostfix(infix, postfix);

    printf("Postfix expression:%s\n", postfix);

    return 0;
}

int space(char symbol){
    return (symbol == ' ' || symbol == '\t');
}

int isOperand(char symbol){
    return (isdigit(symbol) || (symbol >= 'A' && symbol <= 'Z'));
}

int isOperator(char symbol){
    return (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*') || symbol == '%';
}

int precedence(char ch){
	
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

void infixToPostfix(char* infix, char* postfix){
	
    int len = strlen(infix);
    char symbol, next;
    stack s;
    init(&s);

    for (int i = 0; i < len; i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(&s, symbol);
                break;

                case ')':
                    while ((next = pop(&s)) != '(') {
                        char temp[2] = {next, '\0'};
                        strcat(postfix, temp);
                    }
                break;

                default:
                    if (isOperator(symbol)) {
                        while (!is_empty(&s) && precedence(symbol) <= precedence(top(&s))) {
                            char temp[2] = {pop(&s), '\0'};
                            strcat(postfix, temp);
                        }
                        push(&s, symbol);
                    } else if (isOperand(symbol)) {
                        size_t j = 0;
				        char operand[20]; // Adjust the size based on your maximum expected operand size
				
				        while (isOperand(symbol)) {
				            operand[j++] = symbol;
				            symbol = infix[++i];
				        }
				        
				        operand[j] = '\0';
				        i--; // Decrement i to revisit the current symbol in the next loop iteration
				
				        size_t len = strlen(postfix);
				        strcat(postfix, operand); // Append the operand to postfix
				        strcat(postfix, " ");     // Separate operands with spaces
                    }
                break;
            }
        }
    }

    while (!is_empty(&s)) {
        char temp[2] = {pop(&s), '\0'};
        strcat(postfix, temp);
    }
}
