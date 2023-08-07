#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    double data;
    struct Node* next;
} Node;

typedef struct stack{
    Node* top;
}stack;


void init(stack* s){
    s->top = NULL;
}

int is_empty(stack* s){
    if(s->top == NULL){
    	return 1;
	}else{
		return 0;
	}
}

void push(stack* s, double item){
    
	Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

double pop(stack* s){
    
	if (is_empty(s)) {
        return -1;  // or any appropriate value to indicate stack underflow
    }

    Node* poppedNode = s->top;
    double poppedData = poppedNode->data;
    s->top = s->top->next;
    free(poppedNode);

    return poppedData;
}

double top(stack* s){
	
    if (is_empty(s)) {
        printf("Stack is empty. Cannot peek item.\n");
        return -1;  // or any appropriate value to indicate stack underflow
    }

    return s->top->data;
}

int size(stack* s){
    
	int count = 0;
    Node* current = s->top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void clear(stack* s){
    
	while (!is_empty(s)) {
        pop(s);
    }
    
    printf("Stack is cleared successfully.\n");
}

void printStack(stack* s){
    
	if (is_empty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    Node* current = s->top;
    while (current != NULL) {
        printf("%.2lf ", current->data);
        current = current->next;
    }
    printf("\n");
}

