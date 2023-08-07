#include <stdio.h>
#include <stdbool.h>
#include "stack.h"


int Min(int a, int b);
void DesignMinStackVoid(stack* s, stack* MinStack);
stack DesignMinStack(stack* s);


int main() {
	
    stack s;
    stack MinStack = DesignMinStack(&s);
    
	printStack(&MinStack);

    
    return 0;
}

int Min(int a, int b){
    
	if (a < b) {
        return a;
    } else {
        return b;
    }
}

void DesignMinStackVoid(stack* s, stack* MinStack){
    
	int val, n = 3;
    
    init(s);
    init(MinStack);

    for (int i = 0; i < n; i++) {
    	printf("Enter a value:");
        scanf("%d", &val);
        push(s, val);
        if (is_empty(MinStack) || val < top(MinStack)) {
            push(MinStack, val);
        } else {
            push(MinStack, top(MinStack));
        }
    }
    
    printStack(MinStack);
}

stack DesignMinStack(stack* s){
	
	int val, n = 3;
    stack MinStack;
    
    init(s);
    init(&MinStack);

    for (int i = 0; i < n; i++) {
    	printf("Enter a value:");
        scanf("%d", &val);
        push(s, val);
        if (is_empty(&MinStack) || val < top(&MinStack)) {
            push(&MinStack, val);
        } else {
            push(&MinStack, top(&MinStack));
        }
    }
	
	return MinStack;
}


