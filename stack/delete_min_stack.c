#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void minStack(stack* s){
	
	int min = top(s); // Initialize the minimum with the top element of the stack

    stack p;
    init(&p);

    while (!is_empty(s)) {
        int value = pop(s);
        if (value < min) {
            // If the current value is smaller than the current minimum, update the minimum
            min = value;
        }
        // Push the value to an auxiliary stack 'p'
        push(&p, value);
    }

    // Restore the original stack from the auxiliary stack 'p'
    while (!is_empty(&p)) {
    	int val = pop(&p);
    	push(s,val);
    	if(val == min){
    		pop(s);
		}
    }

}

int main() {	
    
    stack s;
    
    init(&s);
    
    push(&s,7);
    push(&s,2);
   
    push(&s,4);
    push(&s,5); 
	push(&s,3);
	push(&s,1);
    push(&s,6);
   
    push(&s,8);
    
    printStack(&s);
    
    while(size(&s)){
    	minStack(&s);
		printStack(&s);
	}
    
    return 0;
}


