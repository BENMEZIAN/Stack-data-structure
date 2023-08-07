#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"


void reverse(stack* s){
	
	stack p;
	
	init(&p);
	
	while(!is_empty(s)){
		int temp = pop(s);
		push(&p,temp);
	}
	
	printf("reversed stack:");
	s = &p;
	printStack(s);
}


int main(){
	
	stack s;
	
	init(&s);
	
	push(&s,50);
	push(&s,40);
	push(&s,30);
	push(&s,20);
	push(&s,10);
	
	printf("Original stack:");
	printStack(&s);
	
	reverse(&s);
	
	
    return 0;
}


