#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void nextGreaterElement(int arr[],int n);


int main() {
	
	int arr[] = {3,7,5,9,3,2,4,1,4};
	
	int n = sizeof(arr) / sizeof(arr[0]);
    
	nextGreaterElement(arr, n);
    
    return 0;
}

void nextGreaterElement(int arr[],int n){
	
	stack s;
	int element;
	init(&s);
	
	push(&s,arr[0]);
	
	for (int i = 1; i < n; i++) {
        while (!is_empty(&s) && arr[i] > top(&s)) {
            element = top(&s);
            pop(&s);
            printf("%d --> %d\n", element, arr[i]);
        }

        push(&s, arr[i]);
    }
	
	// Printing remaining elements in the stack with no greater elements
    while (!is_empty(&s)) {
        element = top(&s);
        pop(&s);
        printf("%d --> -1\n", element);
    }
	
	
}



