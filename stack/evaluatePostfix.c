#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "stack_double.h"


int space(char symbol);
int isOperand(char symbol);
int isOperator(char symbol);
int precedence(char ch);
void infixToPostfix(char* infix, char* postfix);

double evaluate(double a,double b, char symbol){
	
	switch(symbol){
		case '+': return a+b;
		case '-': {
			if(a>b){
				return a-b;
			}else if(a<b){
				return b-a;
			}else{
				return 0;
			}
			break;
		}
		case '*': return a*b;
		case '/': return a/b;
		case '%': return fmod(a,b);
		default:
			return 0;
	}
}

double evaluatePostfix(char* postfix) {
    int len = strlen(postfix);
    double res;
    char symbol;
    stack s;
    init(&s);

    for (int i = 0; i < len; i++) {
        symbol = postfix[i];
        if (!space(symbol)) {
            if (isdigit(symbol)) {
                double operand = 0.0;
                int decimalPlaces = 0;

                // Process digits before and after the decimal point
                while (isdigit(symbol) || symbol == '.') {
                    if (symbol == '.') {
                        decimalPlaces = 1;
                    } else {
                        if (decimalPlaces > 0) {
                            operand += (symbol - '0') / pow(10.0, decimalPlaces);
                            decimalPlaces++;
                        } else {
                            operand = operand * 10 + (symbol - '0');
                        }
                    }
                    i++; // Move to the next symbol
                    symbol = postfix[i];
                }

                i--; // Decrement i to revisit the current symbol in the next loop iteration
                push(&s, operand); // Push operand onto the stack
            } else if (isOperator(symbol)) {
                // Handle other operators
                double a = pop(&s);
                double b = pop(&s);
                res = evaluate(b, a, symbol);
                push(&s, res);
            }
        }
    }

    return pop(&s);
}

int main(){
	
    char* infix = "(15+5)-(5-2)";
	char postfix[] = ""; // Initialize an empty postfix string
	
    infixToPostfix(infix, postfix);

    printf("Postfix expression:%s\n", postfix);
    
    double res = evaluatePostfix(postfix);
    
    printf("%lf",res);
    
    
    return 0;
}

int space(char symbol){
    return (symbol == ' ' || symbol == '\t');
}

int isOperand(char symbol){
    return (isdigit(symbol) || (symbol >= 'A' && symbol <= 'Z'));
}

int isOperator(char symbol){
    return (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '%');
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

void infixToPostfix(char* infix, char* postfix) {
	
    int len = strlen(infix);
    char symbol;
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
                    while (!is_empty(&s) && top(&s) != '(') {
                        char temp[2] = {pop(&s), '\0'};
                        strcat(postfix, temp);
                        strcat(postfix, " "); // Separate operators with spaces
                    }
                    pop(&s); // Pop the '('
                break;
                
                default:
                    if (isOperator(symbol)) {
                        while (!is_empty(&s) && precedence(symbol) <= precedence(top(&s))) {
                            char temp[2] = {pop(&s), '\0'};
                            strcat(postfix, temp);
                            strcat(postfix, " "); // Separate operators with spaces
                        }
                        push(&s, symbol);
                    } else if (isOperand(symbol)) {
                        size_t j = 0;
                        char operand[20]; // Adjust the size based on your maximum expected operand size

                        while (isOperand(symbol) || symbol == '.') {
                            operand[j++] = symbol;
                            symbol = infix[++i];
                        }

                        operand[j] = '\0';
                        i--; // Decrement i to revisit the current symbol in the next loop iteration

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
        strcat(postfix, " "); // Separate operators with spaces
    }
}


