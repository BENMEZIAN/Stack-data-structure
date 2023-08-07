#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"



void push_pop(stack* s);
char* reverseString(char* str);
void sortStack(stack* s);
bool isMatchedPair(char ch,char ch1);
void isBalancedParentheses(char* str);


int main() {
	
	
    
    return 0;
}

void push_pop(stack* s){
	
	init(s);
    
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,3);
    
    printStack(s);
    
    while(!is_empty(s)){
    	pop(s);
	}

    printStack(s);
	
}

char* reverseString(char* str){
	
	int len = strlen(str);
	char* string = (char*)malloc(len*sizeof(char)+1);
	stack s;
	
	for(int i = 0;i<len;i++){
		string[i] = str[i];
	}
	
	init(&s);
	
	for(int i = 0;i<len;i++){
		push(&s,string[i]);
	}
	
	for(int i = 0;i<len;i++){
		if(!is_empty(&s)){
			string[i] = pop(&s);
		}else{
			break;
		}
	}
	
	string[len] = '\0';
	
	return string;
}

void sortStack(stack* s){
	
	stack p;
	
	init(&p);
	
	// pop the first element from (s) and push it onto the (p)
	int firstNode = pop(s);	
	push(&p,firstNode);
	
	// apply the sort algorithm
	while(!is_empty(s)) {
		
        int temp = pop(s); // pop element from the top of (s)
        while(!is_empty(&p)) {
            if(temp < top(&p)) { // if the popped element from (s) is less than the top of (p)
                int tempNode = pop(&p); // pop the top element of (p) and store it in variable (tempNode)
				push(s,tempNode); // push it onto the stack (s)
            }else{
                break; // don't do any thing 
            }
        }
        
        push(&p,temp); // push temp element onto the stack (p)
    }
    
    // Copy elements from auxiliary stack back to the original stack to get sorted order
    while (!is_empty(&p)) {
        int tempNode = pop(&p);
        push(s, tempNode);
    }
    
    clear(&p);
    
	printStack(s);
	
}

bool isMatchedPair(char ch,char ch1){
	
	if((ch == '{' && ch1 == '}') || (ch == '[' && ch1 == ']') || (ch == '(' && ch1 == ')')){
		return true;
	}else{
		return false;
	}
	
}

void isBalancedParentheses(char* str){
	
	int len = strlen(str);
	bool match;
	stack s;
	
	init(&s);
	
	for(int i = 0;i<len;i++){
		if(str[i] == '{' || str[i] == '[' || str[i] == '('){
			push(&s,str[i]);
		}else{
			char ch = pop(&s);
			if(isMatchedPair(ch,str[i])){
				match = true;
			}else{
				match = false;
			}
		}             
	}
	
	if(match == true){
		printf("The expression is balanced.\n");
	}else{
		printf("The expression is not balanced.\n");
	}
		
}


