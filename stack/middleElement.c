#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void getMiddle(stack* s){
	
	stack p;
	
	init(&p);
	
	int k = size(s)/2;
	
	while(k > 0){
		int temp = pop(s);
		push(&p,temp);
		k--;
	}
	
	printf("%d\n",pop(s));
	
	while(!is_empty(&p)){
		int temp = pop(&p);
		push(s,temp);
	}
	
}

int main() {
	
	stack s,p;
	
	init(&s);
	init(&p);
	
	push(&s,23);
	push(&s,32);
	push(&s,26);
	push(&s,15);
	push(&s,88);

	printStack(&s);
	
	while(size(&s)){
		getMiddle(&s);
		printStack(&s);
	}
	
	
	
    return 0;
}


