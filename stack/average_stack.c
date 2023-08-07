#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void averageStack(stack* s){
	
	float avg;
	stack p;
	
	init(&p);
	
	int len = size(s);
	
	int sum = 0;
	while(!is_empty(s)){
		int temp = pop(s);
		sum = sum + temp;
		push(&p,temp);
	}
	
	avg = sum/len;
	
	printf("Average is: %.2lf\n",avg);
	
	while(!is_empty(&p)){
		int temp = pop(&p);
		push(s,temp);
	}
	
}

int main() {
	
	stack s;
	
	init(&s);
	
	push(&s,23);
	push(&s,32);
	push(&s,26);
	push(&s,15);
	push(&s,88);

	printStack(&s);
	
	averageStack(&s);
	
	printStack(&s);
	
	
	
    return 0;
}

