#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void topAndKthElement(stack* s,int k){
	
	stack p;
	
	init(&p);
	
	printf("The top is: %d\n",top(s));
	
	if(k <= size(s)){
		printf("The %dth from the top is:",k);
	
		while(!is_empty(s) && --k > 0){
			int temp = pop(s);
			push(&p,temp);
		}
		
		printf("%d",top(s));
		
		while(!is_empty(&p)){
			int temp = pop(&p);
			push(s,temp);
		}
	}else{
		printf("Invalid k position.\n");
	}
	
}

int main() {
	
	stack s;
	int k = 5;
	
	init(&s);
	
	push(&s,23);
	push(&s,32);
	push(&s,26);
	push(&s,15);
	push(&s,88);

	printStack(&s);
	
	topAndKthElement(&s,4);
	
	
	
	
	
	
	
    return 0;
}


