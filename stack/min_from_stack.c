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
        push(s, pop(&p));
    }

    printf("Minimum element: %d\n", min);
}

int main() {	
    
    stack s;
    
    init(&s);
    
    push(&s,4);
    push(&s,2);
    push(&s,4);
    push(&s,2);
    push(&s,9);
    
    printStack(&s);
    
    minStack(&s);

    
    
    return 0;
}

