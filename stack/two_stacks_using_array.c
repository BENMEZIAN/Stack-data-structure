#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"



int main(){
	
	stack s;
	stack p;
	
	init(&s);
	init(&p);
	
	push(&s,1);
	push(&s,2);
	push(&s,3);
	
	push(&p,10);
	push(&p,20);
	push(&p,30);
	
	printf("%d popped from stack s\n",pop(&s));
	printf("%d popped from stack s\n",pop(&s));	
	printf("%d popped from stack s\n",pop(&s));
	
	printf("-----------------------\n");
	
	printf("%d popped from stack p\n",pop(&p));
	printf("%d popped from stack p\n",pop(&p));	
	printf("%d popped from stack p\n",pop(&p));


	
    
    return 0;
}


