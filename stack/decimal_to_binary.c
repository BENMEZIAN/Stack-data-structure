#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void decimalToBinary(int n){
	
	int rem;
	stack p;
	
	init(&p);
	
	while(n>0){
		rem = n%2;
		push(&p,rem);
		n = n/2;
	}
	
	while(!is_empty(&p)){
		int temp = pop(&p);
		printf("%d",temp);
	}
	
}

int main() {
	
	int n = 10;
	
	
	decimalToBinary(n);
	
	
    return 0;
}

